#include "NswButton.h"

NswButton::NswButton(const NswPort &port) {
    pin = port.pin1; // Use the first digital pin of the selected port
    pinMode(pin, INPUT_PULLUP); // Enable internal pull-up resistor
}

bool NswButton::isPressed() {
    return digitalRead(pin) == HIGH; // Button is active LOW
}
