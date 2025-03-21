#include <NswInfraredReceiver.h>

// 📌 Infraqizil sensorni PORT_1 ga ulaymiz (pin 2, 3)
NswInfraredReceiver ir(PORT_1);

void setup() {
    Serial.begin(9600); // 📌 Serial monitor uchun baud rate 9600
    ir.begin();         // 📌 IR qabul qiluvchini ishga tushiramiz
    Serial.println("IR Qabul qiluvchi ishga tushdi. Masofaviy pult tugmachasini bosing.");
}

void loop() {
    unsigned long signal = ir.getSignal(); // 📌 IR signalini qabul qilamiz

    if (signal != 0) { // 📌 Agar signal kelgan bo‘lsa
        Serial.print("Qabul qilingan IR kodi: ");
        Serial.println(signal, HEX); // 📌 HEX formatda chiqaramiz
    }
}
