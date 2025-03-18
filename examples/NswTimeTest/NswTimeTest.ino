#include <Wire.h>
#include "NswTime.h"

NswTime clock;

void setup() {
    Serial.begin(9600);
    clock.begin();

    // Uncomment below to manually set time and date
    // clock.setTime(0, 30, 12);  // 12:30:00
    // clock.setDate(2, 18, 3, 25);  // Tuesday, 18 March 2025
}

void loop() {
    Serial.print("Time: ");
    Serial.println(clock.getTime());

    Serial.print("Date: ");
    Serial.println(clock.getDate());

    delay(1000);
}
