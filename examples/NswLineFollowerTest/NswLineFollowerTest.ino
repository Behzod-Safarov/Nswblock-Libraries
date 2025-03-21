#include <NswLineFollower.h>

// 📌 Chiziq kuzatuvchi datchikni PORT_4 ga ulaymiz (pin 8, 9)
NswLineFollower chiziqDatchik(PORT_4);

void setup() {
    Serial.begin(115200); // 📌 Seriyali monitorni ishga tushiramiz
}

void loop() {
    uint8_t chap = chiziqDatchik.oqishChap();   // 📌 Chap sensor qiymati
    uint8_t ong = chiziqDatchik.oqishOng();    // 📌 O'ng sensor qiymati

    Serial.print("Chap: ");
    Serial.print(chap);  // 📌 Chap sensorni chiqarish (1 - qora, 0 - oq)
    Serial.print(" | Ong: ");
    Serial.println(ong); // 📌 O'ng sensorni chiqarish (1 - qora, 0 - oq)

    delay(200); // ⏳ 200ms kutish
}
