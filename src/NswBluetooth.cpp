#include "NswBluetooth.h"

// Default constructor using PORT_4 (pins 8 and 9)
NswBluetooth::NswBluetooth() 
    : SoftwareSerial(8, 9, false), // RX = pin1 (8), TX = pin2 (9), no inverse logic
      NswPort(PORT_4)
{
}

// Constructor with specified port
NswBluetooth::NswBluetooth(Port port) 
    : SoftwareSerial(pin1, pin2, false), // RX = pin1, TX = pin2 from NswPort
      NswPort(port)
{
}