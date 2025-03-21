#include <NswOledDisplay.h>

// 📌 OLED displey obyektini yaratamiz
NswOledDisplay displey;

void setup() {
    Serial.begin(9600);

    // 📌 OLED displeyni ishga tushiramiz
    if (!displey.begin()) {
        Serial.println("OLED ishlamadi!"); 
        while (1); // ⚠ Displey ishlamasa, kod shu joyda to‘xtaydi
    }

    displey.tozalash(); // 📌 Ekranni tozalash
    displey.matnChiqar("Salom, Nsw!", 10, 20, 2); // 📌 Matn chiqarish (x = 10, y = 20, o‘lcham = 2)
    displey.yangilash(); // 📌 Displeyga yangilanishni qo‘llash
}

void loop() {
    static int hisoblagich = 0;

    displey.tozalash(); // 📌 Har safar eski ma'lumotni o‘chiramiz
    displey.matnChiqar("Hisob:", 10, 10, 2); // 📌 "Hisob:" yozuvi
    displey.sonChiqar(hisoblagich++, 50, 30, 3); // 📌 Hisoblagich sonini chiqarish
    displey.yangilash(); // 📌 Yangilash

    delay(1000); // ⏳ 1 soniya kutish
}
