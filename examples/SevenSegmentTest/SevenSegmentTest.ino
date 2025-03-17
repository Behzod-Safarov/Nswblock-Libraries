#include <NswSevenSegmentDisplay.h>

NswSevenSegmentDisplay display(PORT_5);  // Example: Using PORT_5 (6, 7)

void setup() {
    Serial.begin(115200);
    display.displayNumber(1234);
}

void loop() {
    for (int i = 0; i <= 9999; i++) {
        display.displayNumber(i);
        delay(500);
    }
}
