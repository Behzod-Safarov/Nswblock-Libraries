#include <Nsw7SegmentDisplay.h>

Nsw7SegmentDisplay display(PORT_1); // Create display object using PORT_1

void setup() {
  // Display different types of values
  display.display(12345);      // Display uint16_t
  display.display(-12345);     // Display int16_t
  display.display(12.34f);     // Display float
}

void loop() {
  // You can add any looping functionality here if needed
}
