#include <NswButton.h>  // NswBlock uchun tugma (button) kutubxonasi chaqirilmoqda

// 📌 Tugmani PORT_4 ga ulaymiz (PORT_4 = pin 8 va 9)
NswButton button(PORT_4);  

void setup() {
    Serial.begin(115200);  // 📌 Seriyali monitor orqali ma'lumot chiqarish uchun boshlaymiz
}

void loop() {
    // 📌 Tugma bosilganmi yoki yo‘qmi tekshiramiz
    if (button.isPressed()) {  
        Serial.println("Tugma bosildi!");  // Agar tugma bosilsa, ekranga chiqaramiz
    } else {
        Serial.println("Tugma qo‘yib yuborildi!");  // Agar tugma qo‘yib yuborilsa, ekranga chiqaramiz
    }
    
    delay(200);  // 📌 Har 200 millisekundda bir marta tugma holatini tekshiramiz
}
