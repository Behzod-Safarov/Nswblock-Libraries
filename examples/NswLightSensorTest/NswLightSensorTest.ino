#include "NswLightSensor.h"

NswLightSensor lightSensor(PORT_2);

void setup() {
    Serial.begin(9600);
    lightSensor.begin();
}

void loop() {
    int lightValue = lightSensor.readValue();
    Serial.print("Light Intensity: ");
    Serial.println(lightValue);

    if (lightSensor.isBright(500)) {
        Serial.println("It's bright! 🌞");
    } else {
        Serial.println("It's dark... 🌙");
    }

    delay(1000);
}
