#include "NswLineFollower.h"

NswLineFollower::NswLineFollower(const NswPort &port) {
    leftPin = port.pin1;
    rightPin = port.pin2;

    pinMode(leftPin, INPUT);
    pinMode(rightPin, INPUT);
}

uint8_t NswLineFollower::readLeftSensor() {
    return digitalRead(leftPin);
}

uint8_t NswLineFollower::readRightSensor() {
    return digitalRead(rightPin);
}

uint8_t NswLineFollower::readSensors() {
    return (digitalRead(leftPin) << 1) | digitalRead(rightPin); 
}
