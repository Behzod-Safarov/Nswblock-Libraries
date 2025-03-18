#ifndef NSW_TOUCH_SENSOR_H
#define NSW_TOUCH_SENSOR_H

#include <Arduino.h>
#include "NswPort.h"

class NswTouchSensor {
public:
    NswTouchSensor(Port port);  // Constructor using Port enum

    bool isTouched();  // Returns true if the sensor is touched

private:
    uint8_t touchPin;
};

#endif // NSW_TOUCH_SENSOR_H
