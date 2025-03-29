#ifndef NSW_7SEGMENTDISPLAY_H
#define NSW_7SEGMENTDISPLAY_H

#include <Arduino.h>
#include "NswPort.h"

class Nsw7SegmentDisplay {
public:
    Nsw7SegmentDisplay(Port port);
    void begin();
    void clear();
    void setBrightness(uint8_t level);
    void displayNumber(uint16_t number);
    void display(float number);

private:
    uint8_t _clkPin;
    uint8_t _dioPin;
    void startSignal();
    void stopSignal();
    void writeByte(uint8_t data);
    void displayDigit(uint8_t position, uint8_t digit, bool dot);
    static const uint8_t digitMap[];
    static const uint8_t DIGIT_MAP_SIZE = 10;
};

#endif // NSW_7SEGMENTDISPLAY_H