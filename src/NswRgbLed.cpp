#include "NswRGBLed.h"

NswRGBLed::NswRGBLed(Port port) {
    NswPort p(port);
    _pin = p.pin2;  // PORT_4 -> pin2 = 9
    _brightness = 255;
    clear();  // Initialize with all LEDs off
}

void NswRGBLed::begin() {
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
    clear();
    show();
}

void NswRGBLed::clear() {
    for (uint8_t i = 0; i < LED_COUNT * 3; i++) {
        _pixels[i] = 0;
    }
}

void NswRGBLed::setBrightness(uint8_t level) {
    _brightness = level > 255 ? 255 : level;
}

void NswRGBLed::sendByte(uint8_t data) {
    uint8_t mask = 0x80;
    uint8_t port = digitalPinToPort(_pin);
    volatile uint8_t *portReg = portOutputRegister(port);
    uint8_t pinMask = digitalPinToBitMask(_pin);

    noInterrupts();
    for (uint8_t i = 0; i < 8; i++) {
        if (data & mask) {
            // Send '1' (0.8µs high, 0.45µs low)
            *portReg |= pinMask;  // High
            asm volatile(
                "nop\n\t nop\n\t nop\n\t nop\n\t"
                "nop\n\t nop\n\t nop\n\t nop\n\t"  // ~0.5µs
            );
            *portReg &= ~pinMask; // Low
            asm volatile(
                "nop\n\t nop\n\t nop\n\t"  // ~0.1875µs
            );
        } else {
            // Send '0' (0.4µs high, 0.85µs low)
            *portReg |= pinMask;  // High
            asm volatile(
                "nop\n\t nop\n\t"  // ~0.125µs
            );
            *portReg &= ~pinMask; // Low
            asm volatile(
                "nop\n\t nop\n\t nop\n\t nop\n\t"
                "nop\n\t nop\n\t nop\n\t"  // ~0.4375µs
            );
        }
        mask >>= 1;
    }
    interrupts();
}

void NswRGBLed::sendPixel(uint8_t r, uint8_t g, uint8_t b) {
    r = (r * _brightness) >> 8;
    g = (g * _brightness) >> 8;
    b = (b * _brightness) >> 8;
    sendByte(g);  // GRB order
    sendByte(r);
    sendByte(b);
}

void NswRGBLed::sendArray(uint8_t *data, uint16_t length) {
    noInterrupts();
    for (uint16_t i = 0; i < length; i++) {
        sendByte(data[i]);
    }
    interrupts();
    delayMicroseconds(80);  // Latch
}

void NswRGBLed::setColor(uint8_t red, uint8_t green, uint8_t blue) {
    for (uint8_t i = 0; i < LED_COUNT; i++) {
        setColor(i, red, green, blue);
    }
}

void NswRGBLed::setColor(uint8_t index, uint8_t red, uint8_t green, uint8_t blue) {
    if (index < LED_COUNT) {
        uint8_t tmp = index * 3;
        _pixels[tmp] = green;
        _pixels[tmp + 1] = red;
        _pixels[tmp + 2] = blue;
    }
}

void NswRGBLed::show() {
    sendArray(_pixels, LED_COUNT * 3);
}