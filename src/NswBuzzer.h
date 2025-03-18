#ifndef NSW_BUZZER_H
#define NSW_BUZZER_H

#include <Arduino.h>
#include "NswPort.h" // Ensure we use port-based mapping

#define DEFAULT_NOTE_DURATION 300  // Default note duration in ms

class NswBuzzer {
public:
    NswBuzzer(NswPort port);
    void begin();
    void playNote(int frequency, int duration = DEFAULT_NOTE_DURATION);
    void playMelody();
    void playBeep(int count, int duration = 100, int pause = 100);
    void playCustomMelody(int notes[], int durations[], int length);
    void setVolume(uint8_t level);
    void stop();

private:
    uint8_t buzzerPin;
    uint8_t volume; 
    int melody[8] = {262, 294, 330, 349, 392, 440, 494, 523}; // C D E F G A B C
};

#endif // NSW_BUZZER_H
