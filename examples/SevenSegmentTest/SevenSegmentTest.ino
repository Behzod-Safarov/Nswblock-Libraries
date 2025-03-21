#include <NswSevenSegmentDisplay.h>

// 📌 7 segmentli displeyni PORT_5 ga ulaymiz (pinlar: 6, 7)
NswSevenSegmentDisplay displey(PORT_5);

void setup() {
    Serial.begin(115200); // 📌 Serial monitorni ishga tushirish
    displey.displayNumber(1234); // 📌 Boshlang'ich sonni chiqarish
}

void loop() {
    for (int son = 0; son <= 9999; son++) { // 📌 0 dan 9999 gacha sanash
        displey.displayNumber(son); // 📌 Raqamni displeyga chiqarish
        delay(500); // ⏳ 0.5 soniya kutish
    }
}
