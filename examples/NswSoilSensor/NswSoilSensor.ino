#include <NswPort.h>
#include <NswSoilSensor.h>

// 📌 Tuproq namligi sensori PORT_2 ga ulangan (A0, A1)
NswSoilSensor tuproqSensor(PORT_2);

void setup() {
    Serial.begin(9600); // 📌 Serial monitorni ishga tushirish
}

void loop() {
    int analogQiymat = tuproqSensor.readRaw(); // 📌 Analog qiymatni o'qish (0-1023)
    int namlikFoiz = tuproqSensor.readPercentage(); // 📌 Namlik foizda (0-100%)

    Serial.print("Analog qiymat: ");
    Serial.print(analogQiymat);
    Serial.print(" | Namlik: ");
    Serial.print(namlikFoiz);
    Serial.println("%");

    delay(1000); // ⏳ 1 soniya kutish
}
