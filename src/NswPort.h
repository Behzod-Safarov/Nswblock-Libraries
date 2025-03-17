#ifndef NSW_PORT_H
#define NSW_PORT_H

#include <Arduino.h>

enum Port {
    PORT_1 = 1,
    PORT_2,
    PORT_3,
    PORT_4,
    PORT_5,
    PORT_6,
    PORT_7
};

class NswPort {
public:
    uint8_t pin1, pin2;
    uint8_t sclPin, sdaPin; // I2C pins

    NswPort(Port port) {
        switch (port) {
            case PORT_1: pin1 = 2; pin2 = 3; break;
            case PORT_2: pin1 = A0; pin2 = A1; break;
            case PORT_3: pin1 = A2; pin2 = A3; break;
            case PORT_4: pin1 = 8; pin2 = 9; break;
            case PORT_5: pin1 = 6; pin2 = 7; break;
            case PORT_6: pin1 = 0; pin2 = 1; break; // TXD, RXD
            case PORT_7: pin1 = 4; pin2 = 5; break;
        }

        // Assign I2C pins (assume SDA=SCL for all ports)
        sclPin = pin1;
        sdaPin = pin2;
    }
};

#endif // NSW_PORT_H
