#ifndef NSW_BUTTON_H
#define NSW_BUTTON_H

#include <Arduino.h>
#include "NswPort.h"

class NswButton {
public:
    NswButton(const NswPort &port);
    bool isPressed(); // Returns true if the button is pressed

private:
    uint8_t pin;
};

#endif // NSW_BUTTON_H
