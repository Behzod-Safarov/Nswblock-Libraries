#include "NswLed.h"

// Constructor: Initialize LED with Port enum
NswLed::NswLed(Port port) {
    ledPin = NswPort(port).pin2; // Use pin1 as LED pin
    pinMode(ledPin, OUTPUT);
    state = LOW;
}

// Turn LED on
void NswLed::on() {
    state = HIGH;
    digitalWrite(ledPin, state);
}

// Turn LED off
void NswLed::off() {
    state = LOW;
    digitalWrite(ledPin, state);
}

// Toggle LED state
void NswLed::toggle() {
    state = !state;
    digitalWrite(ledPin, state);
}

// Blink LED for a duration
void NswLed::blink(unsigned long duration) {
    on();
    delay(duration);
    off();
    delay(duration);
}
