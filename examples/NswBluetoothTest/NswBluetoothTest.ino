#include <NswBluetooth.h>

// 📌 Bluetooth modulini PORT_5 ga ulaymiz (PORT_5 = RX: 6, TX: 7)
NswBluetooth bluetooth(PORT_5);

void setup() {
    Serial.begin(9600);  // 📌 Kompyuter bilan serial aloqa uchun
    while (!Serial) {
        ; // 📌 Serial port ulanishini kutamiz
    }

    bluetooth.begin(9600);  // 📌 Bluetooth moduli uchun baud tezligini o‘rnatamiz (HC-05 va HC-06 odatda 9600)
    Serial.println("Bluetooth PORT_5 da ishga tushdi (RX=6, TX=7). Ma'lumot yuboring...");
}

void loop() {
    // 📌 Bluetooth orqali kelgan ma’lumotni tekshiramiz
    if (bluetooth.available()) {
        char c = bluetooth.read();  // 📌 Kelgan ma'lumotni o‘qiymiz
        Serial.print("Bluetoothdan qabul qilindi: ");
        Serial.println(c);

        // 📌 Qayta javob qaytaramiz (Echo)
        bluetooth.print("Echo: ");
        bluetooth.println(c);
    }

    // 📌 Kompyuterdan (Serial Monitor) yozilgan ma’lumotni Bluetooth'ga jo‘natamiz
    if (Serial.available()) {
        char c = Serial.read();
        bluetooth.write(c);
        Serial.print("Bluetooth'ga yuborildi: ");
        Serial.println(c);
    }

    delay(10);  // 📌 Overload bo‘lmasligi uchun kichik kechikish
}
