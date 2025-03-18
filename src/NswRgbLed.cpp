#include "NswRgbLed.h"

// Constructor: Only takes port, not LED count
NswRgbLed::NswRgbLed(Port port) {
    pin = NswPort(port).pin2;
    strip = nullptr;
}

// Begin function initializes the LEDs
void NswRgbLed::begin(uint8_t numLeds) {
    ledCount = numLeds;
    strip = new Adafruit_NeoPixel(ledCount, pin, NEO_GRB + NEO_KHZ800);
    strip->begin();
    strip->show();
}

// Set color with separate R, G, B values
void NswRgbLed::setColor(uint8_t index, uint8_t red, uint8_t green, uint8_t blue) {
    if (index < ledCount) {
        strip->setPixelColor(index, strip->Color(red, green, blue));
    }
}

// Apply the color changes
void NswRgbLed::show() {
    strip->show();
}

// Turn off all LEDs
void NswRgbLed::clear() {
    strip->clear();
    strip->show();
}
