#include <NswLed.h>

// 📌 LEDni PORT_4 ga ulaymiz (pin 8, 9)
NswLed led(PORT_4);

void setup() {
    // 📌 setup() bo‘limida hech qanday sozlama talab qilinmaydi.
}

void loop() {
    led.on();    // 📌 LEDni yoqish
    delay(1000); // ⏳ 1 soniya kutish
    
    led.off();   // 📌 LEDni o‘chirish
    delay(1000); // ⏳ 1 soniya kutish
    
    led.toggle(); // 📌 LEDni hozirgi holatiga qarab yoqish yoki o‘chirish
    delay(1000);  // ⏳ 1 soniya kutish
    
    led.blink(500); // 📌 LEDni har 500ms da miltillatish
}
