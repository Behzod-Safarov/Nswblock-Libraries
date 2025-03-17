#include "NswSerial.h"

void NswSerial::begin(long baudRate) {
  Serial.begin(baudRate);  // Initialize the serial communication
}

void NswSerial::print(const String &message) {
  Serial.print(message);   // Print the message
}

void NswSerial::println(const String &message) {
  Serial.println(message); // Print the message with a newline
}
