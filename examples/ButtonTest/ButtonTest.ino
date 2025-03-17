#include <NswButton.h>

NswButton button(PORT_4);  // PORT_4 = 8, 9

void setup() {
    Serial.begin(115200);
}

void loop() {
    if (button.isPressed()) {
        Serial.println("Button Pressed!");
    } else {
        Serial.println("Button Released!");
    }
    delay(200);
}
