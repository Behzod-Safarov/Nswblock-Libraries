#include "NswRGBLed.h"

// PORT_4 (pin2=9) bilan 4 ta LED ishlatamiz (avtomatik)
NswRGBLed led(PORT_4);  // LED soni kiritish shart emas

void setup() {
    led.begin();  // LEDlarni ishga tushiramiz
    
    // Har bir LEDni birma-bir sinab ko'ramiz
    led.clear();
    led.setColor(0, 255, 0, 0);  // 1-LED qizil
    led.setColor(1, 0, 255, 0);  // 2-LED yashil
    led.setColor(2, 0, 0, 255);  // 3-LED ko'k
    led.setColor(3, 255, 255, 0);  // 4-LED sariq
    led.show();
    delay(2000);  // 2 soniya kutamiz
}

void loop() {
    // Har bir LEDni navbat bilan yoqamiz
    led.clear();
    led.setColor(0, 255, 0, 0);  // Faqat 1-LED qizil
    led.show();
    delay(1000);
    
    led.clear();
    led.setColor(1, 0, 255, 0);  // Faqat 2-LED yashil
    led.show();
    delay(1000);
    
    led.clear();
    led.setColor(2, 0, 0, 255);  // Faqat 3-LED ko'k
    led.show();
    delay(1000);
    
    led.clear();
    led.setColor(3, 255, 255, 0);  // Faqat 4-LED sariq
    led.show();
    delay(1000);
    
    // Hamma LEDlarni oq qilamiz
    led.setColor(255, 255, 255);  // Oq rang
    led.show();
    delay(2000);
}