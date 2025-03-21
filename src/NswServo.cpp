#include "NswServo.h"

NswServo::NswServo(Port port) {
    NswPort nswPort(port);
    pin = nswPort.pin2; // Use the second pin for servo control
}

void NswServo::attach() {
    servo.attach(pin);
}

void NswServo::write(int angle) {
    servo.write(angle);
}

void NswServo::detach() {
    servo.detach();
}
