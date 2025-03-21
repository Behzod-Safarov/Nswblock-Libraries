#include "NswHumitureSensor.h"

NswHumitureSensor::NswHumitureSensor(Port port) : _port(port), _dht(_port.pin2, DHTTYPE) {
    _dht.begin();  // Initialize the DHT sensor
}

float NswHumitureSensor::getTemperature() {
    return _dht.readTemperature();  // Get temperature in Celsius
}

float NswHumitureSensor::getHumidity() {
    return _dht.readHumidity();  // Get humidity percentage
}
