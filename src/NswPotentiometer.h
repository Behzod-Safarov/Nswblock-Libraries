#ifndef NSW_POTENTIOMETER_H
#define NSW_POTENTIOMETER_H

#include <Arduino.h>
#include "NswPort.h"

class NswPotentiometer {
public:
    NswPotentiometer(const NswPort &port);
    int read(); // Read potentiometer value (0 - 1023)

private:
    uint8_t pin;
};

#endif // NSW_POTENTIOMETER_H
