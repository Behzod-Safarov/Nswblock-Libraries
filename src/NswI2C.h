#ifndef NSW_I2C_H
#define NSW_I2C_H

#include <Wire.h>

class NswI2C {
public:
    static void begin();
    static void writeByte(uint8_t address, uint8_t data);
    static uint8_t readByte(uint8_t address);
};

#endif
