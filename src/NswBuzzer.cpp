#include "NswBuzzer.h"

NswBuzzer::NswBuzzer(NswPort port) {
    buzzerPin = port.pin1; // Using pin1 of the given port
    volume = 10; // Default volume level
}

void NswBuzzer::begin() {
    pinMode(buzzerPin, OUTPUT);
}

void NswBuzzer::playNote(int frequency, int duration) {
    tone(buzzerPin, frequency);
    delay(duration);
    noTone(buzzerPin);
}

void NswBuzzer::playMelody() {
    for (int i = 0; i < 8; i++) {
        playNote(melody[i]);
        delay(100);
    }
}

void NswBuzzer::playBeep(int count, int duration, int pause) {
    for (int i = 0; i < count; i++) {
        tone(buzzerPin, 1000);
        delay(duration);
        noTone(buzzerPin);
        delay(pause);
    }
}

void NswBuzzer::playCustomMelody(int notes[], int durations[], int length) {
    for (int i = 0; i < length; i++) {
        playNote(notes[i], durations[i]);
        delay(50);
    }
}

void NswBuzzer::setVolume(uint8_t level) {
    volume = constrain(level, 0, 10);
    analogWrite(buzzerPin, volume * 25);
}

void NswBuzzer::stop() {
    noTone(buzzerPin);
}
