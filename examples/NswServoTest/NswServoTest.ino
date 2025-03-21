#include <Arduino.h>
#include "NswServo.h"

// 📌 Servo motorni boshqarish uchun obyekt yaratamiz
NswServo servoMotor(PORT_5); // Servo PORT_5 ga ulangan (pin 7)

void setup() {
    Serial.begin(9600); // 📌 Serial monitor uchun baud rate sozlash
    servoMotor.attach();   // 📌 Servo motorni faollashtirish
}

void loop() {
    // 📌 Servo motorni 0° dan 180° gacha harakatlantiramiz
    for (int burchak = 0; burchak <= 180; burchak += 10) {
        servoMotor.write(burchak); // 📌 Servo motorni kerakli burchakka burish
        Serial.print("Servo burchagi: ");
        Serial.println(burchak); // 📌 Burchakni serial monitorga chiqarish
        delay(500); // ⏳ 0.5 soniya kutish
    }

    // 📌 Servo motorni 180° dan 0° gacha qaytaramiz
    for (int burchak = 180; burchak >= 0; burchak -= 10) {
        servoMotor.write(burchak);
        Serial.print("Servo burchagi: ");
        Serial.println(burchak);
        delay(500);
    }
}
