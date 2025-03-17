#include "NswI2C.h"

void NswI2C::begin() {
    Wire.begin();
}

void NswI2C::writeByte(uint8_t address, uint8_t data) {
    Wire.beginTransmission(address);
    Wire.write(data);
    Wire.endTransmission();
}

uint8_t NswI2C::readByte(uint8_t address) {
    Wire.requestFrom(address, (uint8_t)1);
    return Wire.available() ? Wire.read() : 0;
}
