/* Includes ------------------------------------------------------------------*/
#include "NswColorSensor.h"

NswColorSensor::NswColorSensor() {
  _deviceAddress = DEFAULT_ADDRESS;
}

NswColorSensor::NswColorSensor(uint8_t address) {
  _deviceAddress = address;
}

void NswColorSensor::begin(void) {
  Wire.begin();
  writeReg(SYSTEM_CONTROL, SW_RESET | INT_RESET); // SW reset and INT reset
  writeReg(MODE_CONTROL1, MEASURE_160MS);         // Select 160ms measure frequency
  writeReg(MODE_CONTROL2, 0x10);                  // Active and set RGB measure gain
  writeReg(MODE_CONTROL3, 0x02);
  writeReg(INTERRUPT, 0x00);
  writeReg(PERSISTENCE, 0x01);
}

uint8_t NswColorSensor::reportId(void) {
  uint8_t temp = 0;
  readData(MANUFACTURER_ID, &temp, 1);
  return temp;
}

void NswColorSensor::readColorData(void) {
  uint8_t colorData[8] = {0};
  readData(RED_DATA_LSBs, colorData, sizeof(colorData));
  _redValue   = (uint16_t)colorData[1] << 8 | colorData[0];
  _greenValue = (uint16_t)colorData[3] << 8 | colorData[2];
  _blueValue  = (uint16_t)colorData[5] << 8 | colorData[4];
  _clearValue = (uint16_t)colorData[7] << 8 | colorData[6];
}

uint8_t NswColorSensor::readColorDataOneByOne(void) {
  uint8_t id = 0;
  begin();
  id = reportId();
  if (id != CHIP_ID) {
    return NSW_BLACK;
  }
  delay(160); // Delay 160ms transfer time
  readColorData();
  return 0;
}

long NswColorSensor::getColorCode(void) {
  long colorcode = 0;
  uint16_t r, g, b;
  r = _redValue / 20;
  g = _greenValue / 30;
  b = _blueValue / 20;
  if (r > 255) r = 255;
  if (g > 255) g = 255;
  if (b > 255) b = 255;
  colorcode = (long)((long)r << 16) | ((long)g << 8) | (long)b;
  return colorcode;
}

uint8_t NswColorSensor::identifyColor(void) {
  uint8_t result, r, g, b;
  if (readColorDataOneByOne()) {
    return NSW_BLACK; // ID return error!
  }
  if (_redValue < 1200 && _greenValue < 1700 && _blueValue < 1200) {
    if (_blueValue < _redValue && _redValue <= _greenValue) {
      if ((_greenValue + _redValue + _blueValue > 300) && (_greenValue > 1.5 * _redValue) && (_greenValue > _blueValue + _blueValue)) {
        result = NSW_GREEN;
      } else if ((_greenValue > _blueValue + _blueValue) && (_redValue > _blueValue + _blueValue) && (_redValue + _greenValue + _blueValue > 120)) {
        result = NSW_YELLOW;
      } else if (_redValue > 400 && _greenValue > 580 && _blueValue > 320) {
        result = NSW_WHITE;
      } else {
        result = NSW_BLACK;
      }
    } else if (_greenValue < _redValue && _blueValue < _greenValue) {
      if (_redValue + _greenValue + _blueValue > 220) {
        if (_greenValue < 2.4 * _blueValue) {
          result = NSW_RED;
        } else if (_greenValue >= 2.4 * _blueValue) {
          result = NSW_RED;
        } else {
          result = NSW_BLACK;
        }
      } else {
        result = NSW_BLACK;
      }
    } else if (_greenValue <= _blueValue && _redValue < _blueValue) {
      result = NSW_BLUE;
    } else if (_redValue <= _greenValue && _blueValue >= _redValue) {
      if ((_redValue + _greenValue + _blueValue) > 400) {
        if (_greenValue > 2.2 * _redValue && _greenValue > 2.2 * _blueValue) {
          result = NSW_GREEN;
        } else {
          result = NSW_BLUE;
        }
      } else {
        result = NSW_BLACK;
      }
    } else if ((_greenValue < (_redValue + _blueValue)) && ((_greenValue + _redValue + _blueValue) > 700)) {
      result = NSW_WHITE;
    } else if ((_greenValue + _redValue + _blueValue) < 1000) {
      result = NSW_BLACK;
    } else {
      result = NSW_BLACK;
    }
  } else if (_blueValue > _greenValue && _blueValue > _redValue) {
    result = NSW_BLUE;
  } else if ((_redValue > _greenValue) && (_greenValue > _blueValue) && (_redValue > _greenValue)) {
    result = NSW_RED;
  } else {
    r = _redValue / _clearValue;
    g = _greenValue / _clearValue;
    b = _blueValue / _clearValue;
    if (r >= 9 && g <= 4 && b <= 1) {
      result = NSW_RED;
    } else if (r > 10 && g <= 4 && b <= 4) {
      result = NSW_RED;
    } else if (r < 3 && g <= 4 && b < 3) {
      result = NSW_BLACK;
    } else if (r <= 5 && g > 10 && b < 5) {
      result = NSW_GREEN;
    } else if ((r < 5 && g < 5 && b > 10) || (r <= 3 && g >= 8 && b >= 8)) {
      result = NSW_BLUE;
    } else if (r >= 5 && g > 6 && b >= 7) {
      result = NSW_BLUE;
    } else if (r <= 4 && g >= 10 && b >= 6) {
      result = NSW_BLUE;
    } else if (r <= 8 && r >= 6 && g >= 6 && b < 2) {
      result = NSW_YELLOW;
    } else if (r >= 10 && g <= 7 && b < 2) {
      result = NSW_RED;
    } else if (r >= 4 && g >= 9 && b >= 4) {
      result = NSW_WHITE;
    } else {
      result = NSW_WHITE;
    }
  }
  return result;
}

uint8_t NswColorSensor::getResult(void) {
  static uint8_t cnt_ = 0;
  static uint16_t temp[3] = {0};
  uint8_t result, r, g, b;

  readColorData();

  if (_redValue < 1200 && _greenValue < 1700 && _blueValue < 1200) {
    if (_greenValue + _redValue + _blueValue < 700) {
      result = NSW_BLACK;
    } else if (_blueValue < _redValue && _redValue <= _greenValue) {
      if ((_greenValue + _redValue + _blueValue > 300) && (_greenValue > 1.5 * _redValue) && (_greenValue > _blueValue + _blueValue)) {
        result = NSW_GREEN;
      } else if ((_greenValue > _blueValue + _blueValue) && (_redValue > _blueValue + _blueValue) && (_redValue + _greenValue + _blueValue > 120)) {
        result = NSW_YELLOW;
      } else if (_redValue > 450 && _greenValue > 580 && _blueValue > 320) {
        result = NSW_WHITE;
      } else {
        result = NSW_BLACK;
      }
    } else if (_greenValue < _redValue && _blueValue < _greenValue) {
      if ((_redValue + _greenValue + _blueValue > 500) && _redValue > 300) {
        result = NSW_RED;
      } else {
        result = NSW_BLACK;
      }
    } else if (_greenValue <= _blueValue && _redValue < _blueValue) {
      result = NSW_BLUE;
    } else if (_redValue <= _greenValue && _blueValue >= _redValue) {
      if (_redValue + _greenValue + _blueValue > 400) {
        if (_greenValue > 2.2 * _redValue && _greenValue > 2.2 * _blueValue) {
          result = NSW_GREEN;
        } else {
          result = NSW_BLUE;
        }
      } else {
        result = NSW_BLACK;
      }
    } else if ((_greenValue < _redValue + _blueValue) && (_greenValue + _redValue + _blueValue > 700)) {
      result = NSW_WHITE;
    } else {
      result = NSW_BLACK;
    }
  } else {
    r = _redValue / _clearValue;
    g = _greenValue / _clearValue;
    b = _blueValue / _clearValue;
    if (r >= 9 && g <= 4 && b <= 1) {
      result = NSW_RED;
    } else if (r > 10 && g <= 4 && b <= 4) {
      result = NSW_RED;
    } else if (r < 3 && g <= 4 && b < 3) {
      result = NSW_BLACK;
    } else if (r <= 5 && g > 10 && b < 5) {
      result = NSW_GREEN;
    } else if ((r < 5 && g < 5 && b > 10) || (r <= 3 && g >= 8 && b >= 8)) {
      result = NSW_BLUE;
    } else if (r >= 5 && g > 6 && b >= 7) {
      result = NSW_BLUE;
    } else if (r <= 4 && g >= 10 && b >= 6) {
      result = NSW_BLUE;
    } else if (r <= 8 && r >= 6 && g >= 6 && b < 2) {
      result = NSW_YELLOW;
    } else if (r >= 10 && g <= 7 && b < 2) {
      result = NSW_RED;
    } else if (r >= 4 && g >= 9 && b >= 4) {
      result = NSW_WHITE;
    } else {
      result = NSW_WHITE;
    }
  }
  temp[cnt_++] = result;
  if (cnt_ >= 3) cnt_ = 0;
  return (temp[0] + temp[1] + temp[2]) / 3;
}

uint8_t NswColorSensor::getGrayscale(void) {
  uint8_t r, g, b;
  uint16_t gray = 0;

  r = _redValue >> 8;
  g = _greenValue >> 8;
  b = _blueValue >> 8;

  gray = (r * 38 + g * 75 + b * 15) >> 4;
  if (gray > 255) gray = 255;
  return gray;
}

uint16_t NswColorSensor::getColorHue(void) {
  uint8_t r, g, b, max, min, c;
  uint16_t h;

  r = _redValue >> 8;
  g = _greenValue >> 8;
  b = _blueValue >> 8;

  if ((r == g) && (g == b)) {
    h = 0;
  } else {
    max = maxValue(r, g, b);
    min = minValue(r, g, b);
    c = max - min;
    if (max == r) {
      h = ((g - b) / c % 6) * 60;
    } else if (max == g) {
      h = ((b - r) / c + 2) * 60;
    } else if (min == b) {
      h = ((r - g) / c + 4) * 60;
    }
  }
  return h;
}

uint16_t NswColorSensor::getRedData(void) {
  return _redValue;
}

uint16_t NswColorSensor::getGreenData(void) {
  return _greenValue;
}

uint16_t NswColorSensor::getBlueData(void) {
  return _blueValue;
}

uint16_t NswColorSensor::getClearData(void) {
  return _clearValue;
}

int8_t NswColorSensor::writeReg(int16_t reg, uint8_t data) {
  return writeData(reg, &data, 1);
}

int8_t NswColorSensor::readData(uint8_t start, uint8_t *buffer, uint8_t size) {
  int16_t i = 0;
  int8_t return_value = 0;
  Wire.beginTransmission(_deviceAddress);
  return_value = Wire.write(start);
  if (return_value != 1) {
    return I2C_ERROR;
  }
  return_value = Wire.endTransmission(false);
  if (return_value != 0) {
    return return_value;
  }
  delayMicroseconds(1);
  Wire.requestFrom(_deviceAddress, size, (uint8_t)true);
  while (Wire.available() && i < size) {
    buffer[i++] = Wire.read();
  }
  delayMicroseconds(1);
  if (i != size) {
    return I2C_ERROR;
  }
  return 0;
}

int8_t NswColorSensor::writeData(uint8_t start, const uint8_t *pData, uint8_t size) {
  int8_t return_value = 0;
  Wire.beginTransmission(_deviceAddress);
  return_value = Wire.write(start);
  if (return_value != 1) {
    return I2C_ERROR;
  }
  Wire.write(pData, size);
  return_value = Wire.endTransmission(true);
  return return_value;
}

uint8_t NswColorSensor::maxValue(uint8_t r, uint8_t g, uint8_t b) {
  if (r >= g) {
    return (r >= b) ? r : b;
  }
  return (g >= b) ? g : b;
}

uint8_t NswColorSensor::minValue(uint8_t r, uint8_t g, uint8_t b) {
  if (r <= g) {
    return (r <= b) ? r : b;
  }
  return (g <= b) ? g : b;
}