#include "NswLEDMatrix.h"  // 📌 NswBlock LED Matriks kutubxonasini chaqiramiz

// 📌 LED matriksni PORT_4 ga ulaymiz (PORT_4 = 8, 9)
NswLEDMatrix ledMx(PORT_4);

void setup() {
    ledMx.setBrightness(6);  // 📌 Yorqinlik darajasini 6 ga sozlaymiz (0-7 oralig‘ida)
    ledMx.setColorIndex(1);  // 📌 Rang indeksini o‘rnatamiz (agar mavjud bo‘lsa)
}

char *s = "AB";  // 📌 Ekranda chiqariladigan matn

void loop() {
    ledMx.showClock(12, 03, 1);  // 📌 LED ekranda soat 12:03 ni ko‘rsatamiz
    delay(2000);  // 2 soniya kutamiz

    ledMx.drawStr(0, 7, s);  // 📌 "AB" matnini 0,7 koordinatasida chiqaramiz
    delay(2000);  // 2 soniya kutamiz

    ledMx.showNum(1.23);  // 📌 LED ekranda 1.23 sonini chiqaramiz
    delay(2000);  // 2 soniya kutamiz

    ledMx.fillScreen();
    delay(2000);
}
