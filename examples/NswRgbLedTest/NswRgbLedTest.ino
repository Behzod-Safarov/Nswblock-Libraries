#include <NswRgbLed.h>

NswRgbLed rgbLed(PORT_4);  // No LED count in constructor

void setup() {
    rgbLed.begin(4);  // Set LED count inside begin()
}

void loop() {
    rgbLed.setColor(0, 255, 0, 0);   // LED 1 - Red
    rgbLed.setColor(1, 0, 255, 0);   // LED 2 - Green
    rgbLed.setColor(2, 0, 0, 255);   // LED 3 - Blue
    rgbLed.setColor(3, 255, 255, 0); // LED 4 - Yellow
    rgbLed.show();
    delay(1000);

    rgbLed.clear();
    delay(1000);
}
