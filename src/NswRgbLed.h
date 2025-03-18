#ifndef NSW_RGB_LED_H
#define NSW_RGB_LED_H

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "NswPort.h"

class NswRgbLed {
public:
    NswRgbLed(Port port);
    void begin(uint8_t numLeds);
    void setColor(uint8_t index, uint8_t red, uint8_t green, uint8_t blue);
    void show();
    void clear();

private:
    Adafruit_NeoPixel* strip;
    uint8_t pin;
    uint8_t ledCount;
};

#endif // NSW_RGB_LED_H
