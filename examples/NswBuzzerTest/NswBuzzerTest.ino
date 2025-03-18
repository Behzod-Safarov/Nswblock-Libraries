#include "NswBuzzer.h"

NswBuzzer buzzer(PORT_4);

int melody[] = {262, 330, 392, 523};
int durations[] = {300, 300, 300, 500};

void setup() {
    buzzer.begin();
}

void loop() {
    buzzer.playMelody();
    delay(2000);

    buzzer.playBeep(3, 150, 200);
    delay(2000);

    buzzer.playCustomMelody(melody, durations, 4);
    delay(2000);

    buzzer.setVolume(5);
}
