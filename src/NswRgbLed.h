#ifndef NSW_RGBLED_H
#define NSW_RGBLED_H

#include <Arduino.h>
#include "NswPort.h"

class NswRGBLed {
public:
    NswRGBLed(Port port);  // No led_num parameter
    void begin();
    void clear();
    void setBrightness(uint8_t level);
    void setColor(uint8_t red, uint8_t green, uint8_t blue);
    void setColor(uint8_t index, uint8_t red, uint8_t green, uint8_t blue);
    void show();

private:
    static const uint8_t LED_COUNT = 4;  // Fixed 4 LEDs
    uint8_t _pin;
    uint8_t _brightness;
    uint8_t _pixels[LED_COUNT * 3];  // Static array for 4 LEDs (12 bytes)
    void sendByte(uint8_t data);
    void sendPixel(uint8_t r, uint8_t g, uint8_t b);
    void sendArray(uint8_t *data, uint16_t length);
};

#endif // NSW_RGBLED_H