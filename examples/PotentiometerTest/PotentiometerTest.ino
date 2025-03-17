#include <NswPotentiometer.h>

NswPotentiometer potentiometer(PORT_2);  // PORT_2 = A0, A1

void setup() {
    Serial.begin(115200);
}

void loop() {
    int value = potentiometer.read();
    Serial.print("Potentiometer Value: ");
    Serial.println(value);
    delay(500);
}
