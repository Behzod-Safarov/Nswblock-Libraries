#include <Nsw7SegmentDisplay.h>


Nsw7SegmentDisplay display(PORT_4);

void setup() {
    display.setBrightness(7);
}

void loop() {
    display.displayNumber(1111);
    delay(2000);
    
    display.displayDecimal(1, 1, 1, 1);
    delay(2000);
    
    display.clear();
    delay(1000);
}
