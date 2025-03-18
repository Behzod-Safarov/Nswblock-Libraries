#ifndef NswBluetooth_H
#define NswBluetooth_H

#include <stdint.h>
#include <stdbool.h>
#include <Arduino.h>
#include <SoftwareSerial.h>
#include "NswPort.h"

class NswBluetooth : public SoftwareSerial, public NswPort
{
public:
    // Constructors
    NswBluetooth(Port port);
    
    // Default constructor with PORT_4 (pins 8 and 9, a common choice)
    NswBluetooth();

    // Additional methods could be added here if needed
};

#endif // NswBluetooth_H