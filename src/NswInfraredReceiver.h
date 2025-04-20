#ifndef NSW_INFRARED_RECEIVER_H
#define NSW_INFRARED_RECEIVER_H

#include <Arduino.h>
#include "utility/IRremote/IRremote.h"   // IR library (install via Arduino Library Manager)
#include "NswPort.h"    // Include port mapping

class NswInfraredReceiver {
public:
    NswInfraredReceiver(Port port); // Constructor with port selection
    void begin();                   // Initialize the IR receiver
    unsigned long getSignal();       // Get the received IR signal

private:
    uint8_t recvPin;                 // Selected pin for IR receiver
    IRrecv irrecv;                    // IR receiver object
    decode_results results;           // Stores decoded results
};

#endif // NSW_INFRARED_RECEIVER_H
