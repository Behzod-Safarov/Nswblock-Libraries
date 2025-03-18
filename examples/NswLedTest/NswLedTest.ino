#include <NswLed.h>

// Initialize LED on PORT_4
NswLed led(PORT_4);

void setup() {
    // Nothing needed here
}

void loop() {
    led.on();
    delay(1000);
    
    led.off();
    delay(1000);
    
    led.toggle();
    delay(1000);
    
    led.blink(500);
}
