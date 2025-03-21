#ifndef NSW_SOIL_SENSOR_H
#define NSW_SOIL_SENSOR_H

#include <Arduino.h>
#include "NswPort.h"

class NswSoilSensor {
private:
    NswPort port;
    uint8_t analogPin;

public:
    // Constructor accepting a Port enum
    NswSoilSensor(Port portEnum) : port(portEnum) {
        // Only PORT_2 and PORT_3 support analog input
        if (portEnum == PORT_2 || portEnum == PORT_3) {
            analogPin = port.pin2; // Use first pin as analog input
        } else {
            Serial.println("⚠️ ERROR: Soil Sensor can only be connected to PORT_2 or PORT_3!");
        }
    }

    int readRaw();         // Reads raw sensor value (0-1023)
    int readPercentage();  // Reads moisture percentage (0-100%)
};

#endif // NSW_SOIL_SENSOR_H
