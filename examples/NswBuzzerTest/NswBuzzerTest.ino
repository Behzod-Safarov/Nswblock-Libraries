#include "NswBuzzer.h"

// 📌 Buzzer modulini PORT_4 ga ulaymiz (PORT_4 = 8, 9)
NswBuzzer buzzer(PORT_4);

// 📌 Ovoz chastotalari (Hz) va davomiyliklar (millisekund)
int melody[] = {262, 330, 392, 523};   // 📌 Do, Mi, Sol, Do
int durations[] = {300, 300, 300, 500}; // 📌 Har bir notaning davomiyligi

void setup() {
    buzzer.begin(); // 📌 Buzzer ishga tushiriladi
}

void loop() {
    buzzer.playMelody(); // 📌 Oldindan belgilangan melodiyani chalish
    delay(2000);

    buzzer.playBeep(3, 150, 200); // 📌 3 marta qisqa "beep" chiqarish
    delay(2000);

    buzzer.playCustomMelody(melody, durations, 4); // 📌 Moslashtirilgan melodiyani chalish
    delay(2000);

    buzzer.setVolume(5); // 📌 Ovoz balandligini 5 ga o‘rnatish
}
