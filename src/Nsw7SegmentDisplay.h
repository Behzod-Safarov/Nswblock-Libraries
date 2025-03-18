#ifndef NSW7SEGMENTDISPLAY_H
#define NSW7SEGMENTDISPLAY_H

#include <Arduino.h>
#include <TM1637Display.h>
#include "NswPort.h"  // Include the port mapping

class Nsw7SegmentDisplay {
public:
    Nsw7SegmentDisplay(Port port); // Constructor using Port enum

    void setBrightness(uint8_t brightness);
    void displayNumber(int number);
    void displayDecimal(uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4);
    void clear();

private:
    TM1637Display display;
};

#endif // NSW7SEGMENTDISPLAY_H
