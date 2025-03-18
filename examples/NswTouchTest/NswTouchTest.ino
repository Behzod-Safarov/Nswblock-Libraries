#include <NswTouchSensor.h>

// Initialize touch sensor on PORT_4
NswTouchSensor touchSensor(PORT_4);

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (touchSensor.isTouched()) {
        Serial.println("Touch detected!");
    }
    delay(100);
}
