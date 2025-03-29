#ifndef NSWBLOCK_SERVO_H
#define NSWBLOCK_SERVO_H

#include <Arduino.h>
#include <utility/Servo.h>
#include "NswPort.h"

class NswServo {
private:
    Servo servo;
    uint8_t pin;

public:
    NswServo(Port port);
    void attach();
    void write(int angle);
    void detach();
};

#endif // NSWBLOCK_SERVO_H