#include <NswRgbLed.h>

// 📌 RGB LED'larni boshqarish uchun obyekt yaratamiz
NswRgbLed rgbLed(PORT_4);  // LED'lar PORT_4 (pin 8, 9) ga ulangan

void setup() {
    rgbLed.begin(4);  // 📌 4 ta LED ishlatish uchun sozlash
}

void loop() {
    // 📌 Har bir LED'ga rang berish (R, G, B)
    rgbLed.setColor(0, 255, 0, 0);   // LED 1 - Qizil
    rgbLed.setColor(1, 0, 255, 0);   // LED 2 - Yashil
    rgbLed.setColor(2, 0, 0, 255);   // LED 3 - Ko‘k
    rgbLed.setColor(3, 255, 255, 0); // LED 4 - Sariq
    rgbLed.show(); // 📌 LED'larni yoqish
    delay(1000); // ⏳ 1 soniya kutish

    rgbLed.clear(); // 📌 LED'larni o‘chirish
    delay(1000); // ⏳ 1 soniya kutish
}
