#ifndef NSWLED_H
#define NSWLED_H

#include <Arduino.h>
#include "NswPort.h"  // Include port mapping

class NswLed {
public:
    NswLed(Port port); // Constructor using Port enum

    void on();
    void off();
    void toggle();
    void blink(unsigned long duration);

private:
    uint8_t ledPin;
    bool state;
};

#endif // NSWLED_H
