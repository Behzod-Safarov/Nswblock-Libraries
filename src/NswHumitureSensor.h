#ifndef NSW_HUMITURE_SENSOR_H
#define NSW_HUMITURE_SENSOR_H

#include "NswPort.h"
#include <utility/Dht/DHT.h>  // Adafruit DHT library
#define DHTTYPE DHT11  // Specify DHT sensor type

class NswHumitureSensor {
public:
    NswHumitureSensor(Port port);  // Constructor with port enum

    float getTemperature();  // Get temperature in Celsius
    float getHumidity();     // Get humidity in percentage

private:
    NswPort _port;  // Stores port information
    DHT _dht;       // DHT11 sensor instance
};

#endif // NSW_HUMITURE_SENSOR_H
