#ifndef NSW_LIGHT_SENSOR_H
#define NSW_LIGHT_SENSOR_H

#include "NswPort.h"
#include <Arduino.h>

class NswLightSensor {
private:
    uint8_t sensorPin;

public:
    NswLightSensor(NswPort port);
    void begin();
    int readValue();
    bool isBright(int threshold);
};

#endif // NSW_LIGHT_SENSOR_H
