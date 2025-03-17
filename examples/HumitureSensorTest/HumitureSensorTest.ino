#include <NswHumitureSensor.h>

// Humiture sensor connected to PORT_4 (pin 8, 9)
NswHumitureSensor humitureSensor(PORT_4);

void setup() {
    Serial.begin(115200);
    Serial.println("DHT11 Sensor Test Started...");
}

void loop() {
    float temperature = humitureSensor.getTemperature();
    float humidity = humitureSensor.getHumidity();

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    Serial.println("--------------------------");
    delay(2000);
}
