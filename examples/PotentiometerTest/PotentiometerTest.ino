#include <NswPotentiometer.h>

// 📌 Potensiometrni PORT_2 ga ulaymiz (A0, A1)
NswPotentiometer potensiometr(PORT_2);

void setup() {
    Serial.begin(115200); // 📌 Serial monitorni ishga tushiramiz
}

void loop() {
    int qiymat = potensiometr.read(); // 📌 Potensiometr qiymatini o'qish
    Serial.print("Potensiometr qiymati: ");
    Serial.println(qiymat); // 📌 Natijani chiqarish
    delay(500); // ⏳ 0.5 soniya kutish
}
