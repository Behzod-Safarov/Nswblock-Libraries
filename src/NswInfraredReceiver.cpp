#include "NswInfraredReceiver.h"

// Constructor: Initializes the IR receiver with a selected port
NswInfraredReceiver::NswInfraredReceiver(Port port) 
    : recvPin(NswPort(port).pin1), irrecv(recvPin) {}

// Initialize the IR receiver
void NswInfraredReceiver::begin() {
    irrecv.enableIRIn();  // Start the receiver
}

// Get the received IR signal
unsigned long NswInfraredReceiver::getSignal() {
    if (irrecv.decode(&results)) {  // Check if data is received
        unsigned long value = results.value;
        irrecv.resume();            // Get ready for next signal
        return value;
    }
    return 0; // Return 0 if no signal received
}
