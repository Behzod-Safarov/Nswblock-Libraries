#include "Nsw7SegmentDisplay.h"

// Constructor: Initialize display with Port enum
Nsw7SegmentDisplay::Nsw7SegmentDisplay(Port port)
    : display(NswPort(port).pin2, NswPort(port).pin1) {  // Use pin1 as CLK, pin2 as DIO
    display.setBrightness(7);
}

// Set brightness
void Nsw7SegmentDisplay::setBrightness(uint8_t brightness) {
    display.setBrightness(brightness);
}

// Display a number
void Nsw7SegmentDisplay::displayNumber(int number) {
    display.showNumberDec(number, false);
}

// Display digits with decimal points
void Nsw7SegmentDisplay::displayDecimal(uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4) {
    uint8_t digits[] = {
        display.encodeDigit(d1) | 0x80, // First digit with DP
        display.encodeDigit(d2) | 0x80, // Second digit with DP
        display.encodeDigit(d3) | 0x80, // Third digit with DP
        display.encodeDigit(d4)         // Last digit without DP
    };
    display.setSegments(digits);
}

// Clear display
void Nsw7SegmentDisplay::clear() {
    display.clear();
}
