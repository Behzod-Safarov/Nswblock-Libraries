#include "NswGyro.h"

NswGyro::NswGyro()
{
    Device_Address = GYRO_DEFAULT_ADDRESS;
}

NswGyro::NswGyro(uint8_t address)
{
    Device_Address = address;
}

void NswGyro::begin()
{
    gSensitivity = 65.5; // for 500 deg/s, check data sheet
    gx = gy = gz = 0;
    gyrX = gyrY = gyrZ = 0;
    accX = accY = accZ = 0;
    gyrXoffs = gyrYoffs = gyrZoffs = 0;
    
    Wire.begin(); // Use default I2C pins (A4 SDA, A5 SCL on Uno)
    delay(200);
    writeReg(0x6b, 0x00); // close the sleep mode
    delay(100);
    writeReg(0x1a, 0x01); // configure the digital low pass filter
    writeReg(0x1b, 0x08); // set the gyro scale to 500 deg/s
    delay(100);
    deviceCalibration();
}

void NswGyro::update()
{
    static unsigned long last_time = 0;
    int8_t return_value;
    double dt, filter_coefficient;

    return_value = readData(0x3b, i2cData, 14);
    if (return_value != 0) return;

    double ax, ay;
    accX = ((i2cData[0] << 8) | i2cData[1]);
    accY = ((i2cData[2] << 8) | i2cData[3]);
    accZ = ((i2cData[4] << 8) | i2cData[5]);
    gyrX = (((i2cData[8] << 8) | i2cData[9]) - gyrXoffs) / gSensitivity;
    gyrY = (((i2cData[10] << 8) | i2cData[11]) - gyrYoffs) / gSensitivity;
    gyrZ = (((i2cData[12] << 8) | i2cData[13]) - gyrZoffs) / gSensitivity;

    ax = atan2(accX, sqrt(pow(accY, 2) + pow(accZ, 2))) * 180 / PI;
    ay = atan2(accY, sqrt(pow(accX, 2) + pow(accZ, 2))) * 180 / PI;

    dt = (double)(millis() - last_time) / 1000;
    last_time = millis();

    if (accZ > 0) {
        gx = gx - gyrY * dt;
        gy = gy + gyrX * dt;
    } else {
        gx = gx + gyrY * dt;
        gy = gy - gyrX * dt;
    }
    gz += gyrZ * dt;
    gz = gz - 360 * floor(gz / 360);
    if (gz > 180) gz -= 360;

    filter_coefficient = 0.5 / (0.5 + dt);
    gx = gx * filter_coefficient + ax * (1 - filter_coefficient);
    gy = gy * filter_coefficient + ay * (1 - filter_coefficient);
}

void NswGyro::fast_update()
{
    static unsigned long last_time = 0;
    int8_t return_value;
    double dt = (double)(millis() - last_time) / 1000.0;
    last_time = millis();

    return_value = readData(0x3b, i2cData, 14);
    if (return_value != 0) return;

    double ax, ay;
    accX = ((i2cData[0] << 8) | i2cData[1]);
    accY = ((i2cData[2] << 8) | i2cData[3]);
    accZ = ((i2cData[4] << 8) | i2cData[5]);
    gyrX = (((i2cData[8] << 8) | i2cData[9]) - gyrXoffs) / gSensitivity;
    gyrY = (((i2cData[10] << 8) | i2cData[11]) - gyrYoffs) / gSensitivity;
    gyrZ = (((i2cData[12] << 8) | i2cData[13]) - gyrZoffs) / gSensitivity;
    ax = atan2(accX, sqrt(pow(accY, 2) + pow(accZ, 2))) * 180 / PI;
    ay = atan2(accY, sqrt(pow(accX, 2) + pow(accZ, 2))) * 180 / PI;

    if (accZ > 0) {
        gx = gx - gyrY * dt;
        gy = gy + gyrX * dt;
    } else {
        gx = gx + gyrY * dt;
        gy = gy - gyrX * dt;
    }
    gz += gyrZ * dt;
    gz = gz - 360 * floor(gz / 360);
    if (gz > 180) gz -= 360;

    gy = 0.98 * gy + 0.02 * ay;
    gx = 0.98 * gx + 0.02 * ax;
}

uint8_t NswGyro::getDevAddr() const { return Device_Address; }
double NswGyro::getAngleX() const { return gx; }
double NswGyro::getAngleY() const { return gy; }
double NswGyro::getAngleZ() const { return gz; }
double NswGyro::getGyroX() const { return gyrX; }
double NswGyro::getGyroY() const { return gyrY; }

double NswGyro::getAngle(uint8_t index) const
{
    switch (index) {
        case 1: return getAngleX();
        case 2: return getAngleY();
        case 3: return getAngleZ();
        default: return 0;
    }
}

void NswGyro::deviceCalibration()
{
    int8_t return_value;
    uint16_t num = 500;
    long xSum = 0, ySum = 0, zSum = 0;

    for (uint16_t x = 0; x < num; x++) {
        return_value = readData(0x43, i2cData, 6);
        xSum += ((i2cData[0] << 8) | i2cData[1]);
        ySum += ((i2cData[2] << 8) | i2cData[3]);
        zSum += ((i2cData[4] << 8) | i2cData[5]);
    }
    gyrXoffs = xSum / num;
    gyrYoffs = ySum / num;
    gyrZoffs = zSum / num;
}

int8_t NswGyro::writeReg(int16_t reg, uint8_t data)
{
    return writeData(reg, &data, 1);
}

int8_t NswGyro::readData(uint8_t start, uint8_t *buffer, uint8_t size)
{
    int16_t i = 0;
    Wire.beginTransmission(Device_Address);
    if (Wire.write(start) != 1) return I2C_ERROR;
    if (Wire.endTransmission(false) != 0) return I2C_ERROR;
    
    delayMicroseconds(1);
    Wire.requestFrom(Device_Address, size, (uint8_t)true);
    while (Wire.available() && i < size) {
        buffer[i++] = Wire.read();
    }
    delayMicroseconds(1);
    return (i != size) ? I2C_ERROR : 0;
}

int8_t NswGyro::writeData(uint8_t start, const uint8_t *pData, uint8_t size)
{
    Wire.beginTransmission(Device_Address);
    if (Wire.write(start) != 1) return I2C_ERROR;
    Wire.write(pData, size);
    return Wire.endTransmission(true);
}