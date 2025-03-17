#include "NswUltrasonic.h"

NswUltrasonic::NswUltrasonic(const NswPort &port) {
    ultrasonicSerial = new SoftwareSerial(port.pin1, port.pin2);  // Set RX, TX
    ultrasonicSerial->begin(9600);
}

float NswUltrasonic::getDistance() {
    delay(600);
    if (ultrasonicSerial->available()) {
        String rawData = ultrasonicSerial->readStringUntil('\n');  // Read the full line
        int startIdx = rawData.indexOf(":");  // Find ':'
        int endIdx = rawData.indexOf("CM");  // Find 'CM'

        if (startIdx != -1 && endIdx != -1) {  // Ensure valid indices
            String numberString = rawData.substring(startIdx + 1, endIdx);  // Extract number
            return numberString.toFloat();  // Convert to float and return
        }
    }
    return -1;  // Return -1 if no valid data
}
