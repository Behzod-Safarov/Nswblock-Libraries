#include "NswTouchSensor.h"

// Constructor: Initialize touch sensor with Port enum
NswTouchSensor::NswTouchSensor(Port port) {
    touchPin = NswPort(port).pin2; // Use pin1 as the touch input pin
    pinMode(touchPin, INPUT);
}

// Check if the touch sensor is activated
bool NswTouchSensor::isTouched() {
    return digitalRead(touchPin) == HIGH;  // Returns true if touched
}
