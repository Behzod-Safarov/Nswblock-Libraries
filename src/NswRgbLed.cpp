#include "NswRGBLed.h"

NswRGBLed::NswRGBLed(Port port, ColorOrder order) 
    : _strip(LED_COUNT, 0, getNeoPixelType(order)) {  // Initialize with placeholder pin
    NswPort p(port);
    _pin = p.pin2;  // PORT_4 -> pin2 = 9
    _brightness = 255;
    _colorOrder = order;
    _strip.updateLength(LED_COUNT);  // Ensure 4 LEDs
    _strip.setPin(_pin);  // Set pin
    clear();  // Initialize with all LEDs off
}

void NswRGBLed::begin() {
    _strip.begin();
    _strip.setBrightness(_brightness);
    clear();
    show();
}

void NswRGBLed::clear() {
    _strip.clear();
}

void NswRGBLed::setBrightness(uint8_t level) {
    _brightness = level > 255 ? 255 : level;
    _strip.setBrightness(_brightness);
}

void NswRGBLed::setColor(uint8_t red, uint8_t green, uint8_t blue) {
    for (uint8_t i = 0; i < LED_COUNT; i++) {
        setColor(i, red, green, blue);
    }
}

void NswRGBLed::setColor(uint8_t index, uint8_t red, uint8_t green, uint8_t blue) {
    if (index < LED_COUNT) {
        switch (_colorOrder) {
            case ColorOrder::GRB:
                _strip.setPixelColor(index, green, red, blue);
                break;
            case ColorOrder::RGB:
                _strip.setPixelColor(index, red, green, blue);
                break;
            case ColorOrder::BRG:
                _strip.setPixelColor(index, blue, red, green);
                break;
            case ColorOrder::RBG:
                _strip.setPixelColor(index, red, blue, green);
                break;
            case ColorOrder::GBR:
                _strip.setPixelColor(index, green, blue, red);
                break;
            case ColorOrder::BGR:
                _strip.setPixelColor(index, blue, green, red);
                break;
        }
    }
}

void NswRGBLed::show() {
    _strip.show();
}

uint32_t NswRGBLed::getNeoPixelType(ColorOrder order) {
    switch (order) {
        case ColorOrder::GRB: return NEO_GRB + NEO_KHZ800;
        case ColorOrder::RGB: return NEO_RGB + NEO_KHZ800;
        case ColorOrder::BRG: return NEO_BRG + NEO_KHZ800;
        case ColorOrder::RBG: return NEO_RBG + NEO_KHZ800;
        case ColorOrder::GBR: return NEO_GBR + NEO_KHZ800;
        case ColorOrder::BGR: return NEO_BGR + NEO_KHZ800;
        default: return NEO_GRB + NEO_KHZ800;  // Default to GRB
    }
}