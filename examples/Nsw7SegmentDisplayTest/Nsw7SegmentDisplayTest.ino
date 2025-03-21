#include <Nsw7SegmentDisplay.h>  // 📌 7 segment displey kutubxonasini chaqiramiz

// 📌 7 segment displeyni PORT_4 ga ulaymiz (PORT_4 = 8, 9)
Nsw7SegmentDisplay display(PORT_4);

void setup() {
    display.setBrightness(7);  // 📌 Yorqinlik darajasini maksimal (7) ga sozlaymiz (0-7 oralig‘ida)
}

void loop() {
    display.displayNumber(1111);  // 📌 Displeyda "1111" sonini ko‘rsatamiz
    delay(2000);  // 2 soniya kutamiz

    display.displayDecimal(1, 1, 1, 1);  // 📌 Har bir raqam ostiga nuqta qo‘shamiz (1.1.1.1)
    delay(2000);  // 2 soniya kutamiz

    display.clear();  // 📌 Displeyni tozalaymiz
    delay(1000);  // 1 soniya kutamiz
}
