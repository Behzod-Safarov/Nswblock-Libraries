#include "Nsw7SegmentDisplay.h"

// Constructor with port parameter
Nsw7SegmentDisplay::Nsw7SegmentDisplay(Port port) : _port(port) {
  // You don't need to set the number of digits here since it's managed internally.
  Serial.begin(9600);  // Initialize serial communication (for debugging)
}

// Method to display uint16_t value
void Nsw7SegmentDisplay::display(uint16_t value) {
  Serial.print("Displaying uint16_t: ");
  Serial.println(value);
}

// Method to display int16_t value
void Nsw7SegmentDisplay::display(int16_t value) {
  Serial.print("Displaying int16_t: ");
  Serial.println(value);
}

// Method to display float value
void Nsw7SegmentDisplay::display(float value) {
  Serial.print("Displaying float: ");
  Serial.println(value, 2);  // Print float with 2 decimal places
}
