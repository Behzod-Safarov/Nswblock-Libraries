#include "NswSoilSensor.h"

int NswSoilSensor::readRaw() {
    return analogRead(analogPin);
}

int NswSoilSensor::readPercentage() {
    int rawValue = analogRead(analogPin);
    return map(rawValue, 1023, 0, 0, 100); // Convert to moisture percentage (0-100%)
}
