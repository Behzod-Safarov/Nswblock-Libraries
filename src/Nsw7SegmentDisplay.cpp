#include "Nsw7SegmentDisplay.h"

const uint8_t Nsw7SegmentDisplay::digitMap[] = {
    0x3f, 0x06, 0x5b, 0x4f, 0x66,  // 0-4
    0x6d, 0x7d, 0x07, 0x7f, 0x6f   // 5-9
};

Nsw7SegmentDisplay::Nsw7SegmentDisplay(Port port) {
    NswPort p(port);
    _clkPin = p.pin2;
    _dioPin = p.pin1;
}

void Nsw7SegmentDisplay::begin() {
    pinMode(_clkPin, OUTPUT);
    pinMode(_dioPin, OUTPUT);
    digitalWrite(_clkPin, HIGH);
    digitalWrite(_dioPin, HIGH);
    clear();
    setBrightness(7);
}

void Nsw7SegmentDisplay::startSignal() {
    digitalWrite(_clkPin, HIGH);
    digitalWrite(_dioPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_dioPin, LOW);
    delayMicroseconds(10);
    digitalWrite(_clkPin, LOW);
    delayMicroseconds(10);
}

void Nsw7SegmentDisplay::stopSignal() {
    digitalWrite(_clkPin, LOW);
    delayMicroseconds(10);
    digitalWrite(_dioPin, LOW);
    delayMicroseconds(10);
    digitalWrite(_clkPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_dioPin, HIGH);
    delayMicroseconds(10);
}

void Nsw7SegmentDisplay::writeByte(uint8_t data) {
    for (uint8_t i = 0; i < 8; i++) {
        digitalWrite(_clkPin, LOW);
        delayMicroseconds(5);
        digitalWrite(_dioPin, (data & 0x01) ? HIGH : LOW);
        delayMicroseconds(5);
        data >>= 1;
        digitalWrite(_clkPin, HIGH);
        delayMicroseconds(5);
    }
    digitalWrite(_clkPin, LOW);
    pinMode(_dioPin, INPUT);
    delayMicroseconds(50);
    while(digitalRead(_dioPin)) {
        delayMicroseconds(1);
        if(digitalRead(_dioPin) == LOW) break;
    }
    digitalWrite(_clkPin, HIGH);
    delayMicroseconds(5);
    pinMode(_dioPin, OUTPUT);
}

void Nsw7SegmentDisplay::clear() {
    startSignal();
    writeByte(0x40);
    stopSignal();
    startSignal();
    writeByte(0xC0);
    for(uint8_t i = 0; i < 4; i++) {
        writeByte(0x00);
    }
    stopSignal();
}

void Nsw7SegmentDisplay::setBrightness(uint8_t brightness) {
    if(brightness > 7) brightness = 7;
    startSignal();
    writeByte(0x88 | brightness);
    stopSignal();
}

void Nsw7SegmentDisplay::displayDigit(uint8_t position, uint8_t digit, bool dot) {
    if(position > 3 || digit > 9) return;
    startSignal();
    writeByte(0x44);
    stopSignal();
    startSignal();
    writeByte(0xC0 | position);
    writeByte(digitMap[digit] | (dot ? 0x80 : 0));
    stopSignal();
}

void Nsw7SegmentDisplay::displayNumber(uint16_t number) {
    if (number > 9999) number = 9999;
    uint8_t digits[4];
    digits[3] = number % 10;
    digits[2] = (number / 10) % 10;
    digits[1] = (number / 100) % 10;
    digits[0] = (number / 1000) % 10;
    displayDigit(0, digits[0], false);
    displayDigit(1, digits[1], false);
    displayDigit(2, digits[2], false);
    displayDigit(3, digits[3], false);
}

void Nsw7SegmentDisplay::display(float number) {
    // Agar raqam chegaradan tashqarida bo'lsa, xatolik ko'rsat
    if (number > 999.9 || number < -99.9) {
        startSignal();
        writeByte(0x40);  // Auto increment mode
        stopSignal();
        startSignal();
        writeByte(0xC0);
        for(uint8_t i = 0; i < 4; i++) {
            writeByte(0x79);  // "E" harfi
        }
        stopSignal();
        return;
    }

    // Manfiy sonlarni tekshirish
    bool isNegative = number < 0;
    if (isNegative) number = -number;

    // Butun va o'nlik qismlarni ajratish
    uint16_t whole = (uint16_t)number;
    uint8_t decimal = (uint8_t)((number - whole) * 10 + 0.5); // Yaxlitlash uchun +0.5

    uint8_t digits[4];
    if (isNegative) {
        // Manfiy son: "-12.3"
        digits[0] = 10; // Minus belgisi uchun maxsus qiymat (digitMap dan tashqari)
        digits[1] = whole / 10;
        digits[2] = whole % 10;
        digits[3] = decimal;
        startSignal();
        writeByte(0x44);
        stopSignal();
        startSignal();
        writeByte(0xC0);  // 0-pozitsiya
        writeByte(0x40);  // Minus belgisi
        stopSignal();
        displayDigit(1, digits[1], false);
        displayDigit(2, digits[2], true);  // Nuqta
        displayDigit(3, digits[3], false);
    } else {
        // Musbat son: "12.34"
        digits[0] = whole / 100;
        digits[1] = (whole / 10) % 10;
        digits[2] = whole % 10;
        digits[3] = decimal;
        displayDigit(0, digits[0], false);
        displayDigit(1, digits[1], false);
        displayDigit(2, digits[2], true);  // Nuqta
        displayDigit(3, digits[3], false);
    }
}