#ifndef NSW_FOUR_BUTTON_H
#define NSW_FOUR_BUTTON_H

#include "NswPort.h"

class NswFourButton {
public:
    NswFourButton(const NswPort &port);
    uint8_t getPressedButton();  // Returns 1, 2, 3, or 4 if a button is pressed, 0 if none
private:
    uint8_t analogPin; // The pin to read the button states
};

#endif // NSW_FOUR_BUTTON_H
