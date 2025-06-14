#include "Nsw4Button.h"
#include <Arduino.h>

NswFourButton::NswFourButton(const NswPort &port) {
    analogPin = port.pin1;  // Assume the button module is connected to the first pin of the port
}

uint8_t NswFourButton::getPressedButton() {
    int value = analogRead(analogPin);  // Read the analog value

    if (value >= 480 && value <= 500) return 1;
    if (value >= 640 && value <= 660) return 2;
    if (value >= 720 && value <= 740) return 3;
    if (value >= 0   && value <= 10)  return 4;

    return 0;  // No button pressed
}
