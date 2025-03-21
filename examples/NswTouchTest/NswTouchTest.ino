#include <NswTouchSensor.h>

// 📌 Sensorni PORT_4 ga uladik
NswTouchSensor tegishSensori(PORT_4);

void setup() {
    Serial.begin(9600); // 📌 Serial monitorni ishga tushiramiz
}

void loop() {
    if (tegishSensori.isTouched()) { // 📌 Agar sensorga tegilgan bo'lsa
        Serial.println("Tegish aniqlandi!"); // 📌 Xabar chiqarish
    }
    delay(100); // ⏳ 100 ms kutish
}
