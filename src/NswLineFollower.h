#ifndef NSW_LINEFOLLOWER_H
#define NSW_LINEFOLLOWER_H

#include <Arduino.h>
#include "NswPort.h"

class NswLineFollower {
public:
    NswLineFollower(const NswPort &port);
    uint8_t readLeftSensor();
    uint8_t readRightSensor();
    uint8_t readSensors();  // Combined function to get both sensors' states

private:
    uint8_t leftPin, rightPin;
};

#endif // NSW_LINEFOLLOWER_H
