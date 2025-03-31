#include "NswOledDisplay.h"

// OLED displey obyektini 1-portga ulaymiz
NswOledDisplay oled(PORT_1);

void setup() {
    Serial.begin(9600);  // Serial portni 9600 tezlikda ishga tushuramiz
    while (!Serial);     // Serial monitor tayyor bo‘lguncha kutamiz
    Serial.println("Ishga tushirilmoqda...");

    // Agar displey ishga tushmasa, xatolik haqida xabar chiqariladi va dastur to‘xtaydi
    if (!oled.begin()) {
        Serial.println("OLED ishga tushmadi!");
        while (1);  // Cheksiz kutish
    }
    Serial.println("OLED ishga tushdi");

    oled.clear();          // Ekranni tozalaymiz
    oled.setContrast(127); // Yorqinlikni o‘rtacha darajada belgilaymiz
    oled.setRotation(0);   // Displey orientatsiyasini to‘g‘rilaymiz
    oled.setTextSize(1);   // Matn o‘lchamini 1 ga belgilaymiz
    oled.setCursor(0, 0);  // Kursorni yuqori chap burchakka qo‘yamiz

    oled.println("Raqamlar: 0123456789");  // Raqamlar yoziladi
    oled.println("Katta: ABCDEF");         // Katta harflar test qilinadi
    oled.println("Kichik: abcdef");        // Kichik harflar test qilinadi
    oled.display();                        // Displey yangilanadi

    Serial.println("Displey yangilandi");
}

void loop() {
    oled.clear();          // Har bir aylanishda displey tozalanadi
    oled.setCursor(0, 0);  // Kursor boshiga qaytadi
    oled.setTextSize(1);   // Matn o‘lchami o‘zgarmaydi

    oled.print("Vaqt: ");
    oled.println(millis() / 1000);  // Ishlagan vaqtni soniyalarda ko‘rsatadi

    oled.println("Test: AbCdEf");   // Aralash harflarni ko‘rsatadi
    oled.display();                 // Displey yangilanadi

    delay(1000);                    // 1 soniya kutadi
}
