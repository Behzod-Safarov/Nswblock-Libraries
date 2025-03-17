#include <NswUltrasonic.h>

NswUltrasonic ultrasonic(PORT_1);  // Using PORT_6 (TXD, RXD)

void setup() {
    Serial.begin(115200);  
    Serial.println("Ultrasonic Sensor Test Started...");
}

void loop() {
    float distance = ultrasonic.getDistance();

    if (distance >= 0) {  
        Serial.print("Received Distance: ");
        Serial.print(distance);
        Serial.println(" cm");
    } else {
        Serial.println("No data received...");
    }

    delay(100);
}
