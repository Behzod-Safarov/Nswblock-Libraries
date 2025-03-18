#ifndef NswGyro_H
#define NswGyro_H

#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>
#include <Wire.h>

/* Exported macro ------------------------------------------------------------*/
#define I2C_ERROR                  (-1)
#define GYRO_DEFAULT_ADDRESS       (0x68)

class NswGyro
{
public:
    // Constructors
    NswGyro();
    NswGyro(uint8_t address);

    // Public methods
    void begin();
    void update();
    void fast_update();
    
    uint8_t getDevAddr() const;
    double getAngleX() const;
    double getAngleY() const;
    double getAngleZ() const;
    double getGyroX() const;
    double getGyroY() const;
    double getAngle(uint8_t index) const;

private:
    double  gSensitivity;    // for 500 deg/s, check data sheet
    double  gx, gy, gz;      // Angle values
    double  gyrX, gyrY, gyrZ; // Gyro rates
    int16_t accX, accY, accZ; // Accelerometer values
    double  gyrXoffs, gyrYoffs, gyrZoffs; // Calibration offsets
    uint8_t i2cData[14];
    uint8_t Device_Address;

    void deviceCalibration();
    int8_t writeReg(int16_t reg, uint8_t data);
    int8_t readData(uint8_t start, uint8_t *buffer, uint8_t size);
    int8_t writeData(uint8_t start, const uint8_t *pData, uint8_t size);
};

#endif // NswGyro_H