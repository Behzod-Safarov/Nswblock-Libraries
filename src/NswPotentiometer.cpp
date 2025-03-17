#include "NswPotentiometer.h"

NswPotentiometer::NswPotentiometer(const NswPort &port) {
    pin = port.pin1;  // Use the first analog pin of the selected port
}

int NswPotentiometer::read() {
    return analogRead(pin);
}
