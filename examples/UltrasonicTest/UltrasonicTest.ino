#include <NswUltrasonic.h>

// 📌 Ultrasonik sensorni PORT_1 ga ulaymiz
NswUltrasonic ultratovush(PORT_1);  

void setup() {
    Serial.begin(115200);  
    Serial.println("🔎 Ultrasonik sensor testi boshlandi...");
}

void loop() {
    float masofa = ultratovush.getDistance(); // 📌 Masofani o'lchash

    if (masofa >= 0) {  
        Serial.print("📏 Masofa: ");
        Serial.print(masofa);
        Serial.println(" cm");
    } else {
        Serial.println("⚠️ Ma'lumot olinmadi...");
    }

    delay(100); // ⏳ 0.1 soniya kutish
}
