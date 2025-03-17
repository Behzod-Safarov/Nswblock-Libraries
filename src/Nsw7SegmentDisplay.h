#ifndef NSw7SegmentDisplay_H
#define NSw7SegmentDisplay_H

#include <Arduino.h>
#include "NswPort.h"  // Include NswPort header

class Nsw7SegmentDisplay {
  public:
    // Constructor with port selection
    Nsw7SegmentDisplay(Port port);

    // Display methods for different types of values
    void display(uint16_t value);
    void display(int16_t value);
    void display(float value);

  private:
    NswPort _port;  // Port configuration
};

#endif
