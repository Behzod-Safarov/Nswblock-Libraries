#include <NswLineFollower.h>

NswLineFollower lineFollower(PORT_4);  // Example: Using PORT_4 (8, 9)

void setup() {
    Serial.begin(115200);
}

void loop() {
    uint8_t left = lineFollower.readLeftSensor();
    uint8_t right = lineFollower.readRightSensor();
    
    Serial.print("Left: ");
    Serial.print(left);
    Serial.print(" | Right: ");
    Serial.println(right);

    delay(200);
}
