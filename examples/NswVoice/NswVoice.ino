#include "NswPort.h"     // Portlarni belgilovchi kutubxona
#include "NswVoice.h"    // Mikrofon moduli kutubxonasi

NswVoice voice(PORT_2);  // Mikrofon PORT_2 ga ulangan (A0 kirish pini orqali)

void setup() {
    Serial.begin(9600);           // Serial monitor ochiladi (tezlik: 9600 baud)
    voice.begin();                // Mikrofon kirish pini INPUT holatida ishga tushiriladi
    voice.setThreshold(500);      // Threshold qiymati o‘rnatiladi (masalan 550) — bu sezuvchanlik darajasidir
}

void loop() {
    int sound = voice.readRaw();  // Mikrofon orqali analog signal qiymati o‘qiladi (0–1023)

    Serial.print("Sound Level: ");  // Natija yozuv bilan chiqariladi
    Serial.println(sound);          // Signal qiymati serialga uzatiladi

    if (voice.isSoundDetected()) {  // Agar signal threshold dan katta bo‘lsa:
        Serial.println("🚨 Loud sound detected!");  // Ogohlantirish chiqariladi
    }

    delay(100);  // 100 millisekund kutish — bu signalni barqaror o‘qish uchun kerak
}
