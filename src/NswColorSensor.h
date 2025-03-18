/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _NSW_COLOR_SENSOR_H_
#define _NSW_COLOR_SENSOR_H_

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>
#include <Wire.h>

/* Color result list */
typedef enum {
  NSW_WHITE  = 0,
  NSW_PINKE  = 1,
  NSW_RED    = 2,
  NSW_ORANGE = 3,
  NSW_YELLOW = 4,
  NSW_GREEN  = 5,
  NSW_CYAN   = 6,
  NSW_BLUE   = 7,
  NSW_PURPLE = 8,
  NSW_BLACK  = 9,
  NSW_GOLD   = 10,
} NSW_COLORTYPES;

class NswColorSensor {
public:
  NswColorSensor();                  // Default I2C address constructor
  NswColorSensor(uint8_t address);   // Custom I2C address constructor

  void begin(void);                  // Renamed from sensorInit for Arduino convention
  uint8_t reportId(void);
  void readColorData(void);          // Renamed from colorDataRead
  uint8_t readColorDataOneByOne(void);
  long getColorCode(void);           // Renamed from returnColorCode
  uint8_t identifyColor(void);       // Renamed from colorIdentify
  uint8_t getResult(void);           // Renamed from returnResult
  uint8_t getGrayscale(void);        // Renamed from returnGrayscale
  uint16_t getColorHue(void);        // Renamed from returnColorHue
  uint16_t getRedData(void);         // Renamed from returnRedData
  uint16_t getGreenData(void);       // Renamed from returnGreenData
  uint16_t getBlueData(void);        // Renamed from returnBlueData
  uint16_t getClearData(void);       // Renamed from returnColorData

private:
  static const uint8_t DEFAULT_ADDRESS = 0x38; // Hidden default I2C address
  uint8_t _deviceAddress;
  uint16_t _redValue;
  uint16_t _greenValue;
  uint16_t _blueValue;
  uint16_t _clearValue;

  // Register definitions (hidden from user)
  static const uint8_t SYSTEM_CONTROL  = 0x40;
  static const uint8_t MODE_CONTROL1   = 0x41;
  static const uint8_t MODE_CONTROL2   = 0x42;
  static const uint8_t MODE_CONTROL3   = 0x44;
  static const uint8_t RED_DATA_LSBs   = 0x50;
  static const uint8_t MANUFACTURER_ID = 0x92;
  static const uint8_t INTERRUPT       = 0x60;
  static const uint8_t PERSISTENCE     = 0x61;

  static const uint8_t SW_RESET        = 1 << 7;
  static const uint8_t INT_RESET       = 1 << 6;
  static const uint8_t MEASURE_160MS   = 0x00;
  static const uint8_t I2C_ERROR       = -1;
  static const uint8_t CHIP_ID         = 0xE0;

  int8_t writeReg(int16_t reg, uint8_t data);
  int8_t readData(uint8_t start, uint8_t *buffer, uint8_t size);
  int8_t writeData(uint8_t start, const uint8_t *pData, uint8_t size);
  uint8_t maxValue(uint8_t r, uint8_t g, uint8_t b);
  uint8_t minValue(uint8_t r, uint8_t g, uint8_t b);
};

#endif // _NSW_COLOR_SENSOR_H_