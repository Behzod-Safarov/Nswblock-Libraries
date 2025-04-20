#ifndef NSW_VOICE_H
#define NSW_VOICE_H

#include <Arduino.h>
#include "NswPort.h"

class NswVoice {
private:
    NswPort port;
    uint8_t micPin;
    int threshold;

public:
    NswVoice(Port p, int soundThreshold = 600);

    void begin();
    int readRaw();
    bool isSoundDetected();
    void setThreshold(int t);
    int getThreshold() const;
};

#endif // NSW_VOICE_H
