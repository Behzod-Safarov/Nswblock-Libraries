#include <NswWiFi.h>

// 📌 Wi-Fi tarmog'ining nomi va paroli
#define SSID "SizningWiFiTarmog'ingiz"
#define PAROL "SizningWiFiParolingiz"

// 📌 Wi-Fi modulini PORT_6 ga ulaymiz (TXD, RXD)
NswWiFi wifi(PORT_6);

void setup() {
    Serial.begin(9600);
    wifi.begin(115200); // 📌 Wi-Fi modulining baud rate'ini sozlash

    Serial.println("📡 Wi-Fi ga ulanmoqda...");
    if (wifi.connectWiFi(SSID, PAROL)) {
        Serial.println("✅ Wi-Fi ga muvaffaqiyatli ulandi!");
        Serial.print("🌐 IP manzil: ");
        Serial.println(wifi.getIP());
    } else {
        Serial.println("❌ Ulanish amalga oshmadi!");
    }
}

void loop() {
    // 📌 Wi-Fi orqali kelayotgan ma'lumotlarni chiqarish
    if (wifi.available()) {
        Serial.write(wifi.read());
    }

    // 📌 Serial monitor orqali Wi-Fi moduliga ma'lumot yuborish
    if (Serial.available()) {
        wifi.write(Serial.read());
    }
}
