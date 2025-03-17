#ifndef NSW_ULTRASONIC_H
#define NSW_ULTRASONIC_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "NswPort.h"

class NswUltrasonic {
public:
    NswUltrasonic(const NswPort &port);  
    float getDistance();  

private:
    SoftwareSerial *ultrasonicSerial;  // SoftwareSerial for ultrasonic
};

#endif // NSW_ULTRASONIC_H
