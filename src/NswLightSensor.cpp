#include "NswLightSensor.h"

NswLightSensor::NswLightSensor(NswPort port) {
    sensorPin = port.pin2;  // Use pin1 of the selected port
}

void NswLightSensor::begin() {
    pinMode(sensorPin, INPUT);
}

int NswLightSensor::readValue() {
    return analogRead(sensorPin); // Read light intensity
}

bool NswLightSensor::isBright(int threshold) {
    return analogRead(sensorPin) > threshold; // Check if brightness exceeds threshold
}
