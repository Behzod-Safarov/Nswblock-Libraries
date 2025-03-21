#include "NswLightSensor.h"

// 📌 Yorug‘lik datchigini PORT_2 ga ulaymiz (pin A0, A1)
NswLightSensor yoruglikDatchik(PORT_2);

void setup() {
    Serial.begin(9600); // 📌 Seriyali monitorni ishga tushiramiz
    yoruglikDatchik.boshlash(); // 📌 Datchikni ishga tushiramiz
}

void loop() {
    int yoruglikQiymati = yoruglikDatchik.oqish(); // 📌 Yorug‘lik darajasini o‘qiymiz
    Serial.print("Yorug‘lik darajasi: ");
    Serial.println(yoruglikQiymati); // 📌 Qiymatni seriyali monitorga chiqaramiz

    if (yoruglikDatchik.yoruglikTekshir(500)) { // 📌 Agar yorug‘lik 500 dan yuqori bo‘lsa
        Serial.println("Yorug‘lik yetarli! 🌞"); // ✅ Yorug‘lik yetarli
    } else {
        Serial.println("Atrof qorong‘i... 🌙"); // ❌ Yorug‘lik past
    }

    delay(1000); // ⏳ 1 soniya kutish
}
