#include "NswOledDisplay.h"

NswOledDisplay oled(PORT_1);

void setup() {
    Serial.begin(9600);
    while (!Serial);  // Wait for Serial Monitor
    Serial.println("Starting...");

    if (!oled.begin()) {
        Serial.println("OLED ishga tushmadi!");
        while (1);
    }
    Serial.println("OLED ishga tushdi");

    oled.clear();
    oled.setContrast(127);  // Mid contrast
    oled.setRotation(0);    // Ensure correct orientation
    oled.setTextSize(1);
    oled.setCursor(0, 0);
    oled.println("Digits: 0123456789");  // Should work
    oled.println("Upper: ABCDEF");       // Should work
    oled.println("Lower: abcdef");       // Test these
    oled.display();

    Serial.println("Display updated");
}

void loop() {
    oled.clear();
    oled.setCursor(0, 0);
    oled.setTextSize(1);
    oled.print("Time: ");
    oled.println(millis() / 1000);  // Digits should work
    oled.println("Test: AbCdEf");   // Mix of working and failing
    oled.display();
    delay(1000);
}