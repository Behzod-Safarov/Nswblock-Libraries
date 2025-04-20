#include "NswVoice.h"

NswVoice::NswVoice(Port p, int soundThreshold) : port(p), threshold(soundThreshold) {
    micPin = port.pin2; // Assume mic signal is on pin1
}

void NswVoice::begin() {
    pinMode(micPin, INPUT);
}

int NswVoice::readRaw() {
    return analogRead(micPin);
}

bool NswVoice::isSoundDetected() {
    return readRaw() > threshold;
}

void NswVoice::setThreshold(int t) {
    threshold = t;
}

int NswVoice::getThreshold() const {
    return threshold;
}
