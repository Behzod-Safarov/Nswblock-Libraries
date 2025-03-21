#include <NswHumitureSensor.h>  // NswBlock uchun DHT11 harorat va namlik sensor kutubxonasi chaqirilmoqda

// 📌 DHT11 sensorini PORT_4 ga ulaymiz (PORT_4 = pin 8 va 9)
NswHumitureSensor humitureSensor(PORT_4);

void setup() {
    Serial.begin(9600);  // 📌 Seriyali monitorni 9600 baud tezlikda ishga tushiramiz
    Serial.println("DHT11 Sensor Test boshlandi...");  
}

void loop() {
    float temperature = humitureSensor.getTemperature();  // 📌 Haroratni o‘qib olish (°C)
    float humidity = humitureSensor.getHumidity();        // 📌 Namlikni o‘qib olish (%)

    // 📌 Haroratni chiqaramiz
    Serial.print("Harorat: ");
    Serial.print(temperature);
    Serial.println(" °C");

    // 📌 Namlikni chiqaramiz
    Serial.print("Namlik: ");
    Serial.print(humidity);
    Serial.println(" %");

    Serial.println("--------------------------");  // 📌 Chiziq qo‘shib, natijalarni ajratamiz
    delay(2000);  // 📌 Har 2 soniyada natijalarni yangilab turamiz
}
