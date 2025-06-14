#include <Wire.h>
#include "NswTime.h"

// 📌 Soat moduli bilan ishlash
NswTime clock;

void setup() {
    Serial.begin(9600);
    clock.begin();

    // 📌 Vaqtni qo‘lda sozlash (faqat bir marta yozish kerak!)
    //               sekond/minut/soat
    // clock.setTime(0, 30, 12);  // ⏰ 12:30:00
    //        hafta kuni/ oy kuni / oy / yil
    // clock.setDate(2, 18, 3, 25);  // 📆 Seshanba, 18-Mart, 2025
}

void loop() {
    Serial.print("⏰ Vaqt: ");
    Serial.println(clock.getTime()); // 📌 Joriy vaqtni olish (HH:MM:SS)

    Serial.print("📆 Sana: ");
    Serial.println(clock.getDate()); // 📌 Joriy sanani olish (DD/MM/YYYY)

    delay(1000); // ⏳ 1 soniyada yangilanadi
}
