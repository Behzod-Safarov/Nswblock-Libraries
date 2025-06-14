#include <Nsw4Button.h>  // NswBlock uchun 4-tugmali modul kutubxonasi chaqirilmoqda

// Bu modul faqatgina analog portlarga(qora rangli) ulana oladi
// 📌 To‘rtta tugmali modulni yaratamiz va PORT_3 ga ulaymiz (PORT_3 = A2, A3)
NswFourButton buttons(PORT_1);

void setup() {
    Serial.begin(9600);  // 📌 Seriyali monitorni 115200 baud tezlikda ishga tushiramiz
    Serial.println("4-Tugmali modul test boshlandi...");  
    Serial.println("Tugmalardan birini bosing, natijani ko‘rish mumkin.");
}

void loop() {
    uint8_t button = buttons.getPressedButton();  // 📌 Qaysi tugma bosilganligini tekshiramiz

    if (button > 0) {  // Agar biror tugma bosilgan bo‘lsa
        Serial.print("Tugma ");
        Serial.print(button);  // 📌 Bosilgan tugma raqamini chiqaramiz
        Serial.println(" bosildi!");
    } else {
        Serial.println("Hech qaysi tugma bosilmadi...");  // 📌 Agar tugma bosilmagan bo‘lsa
    }

    delay(300);  // 📌 300 ms kechikish qo‘shamiz, natijani o‘qish oson bo‘lishi uchun
}
