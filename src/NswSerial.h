#ifndef NSW_SERIAL_H
#define NSW_SERIAL_H

#include <Arduino.h>

class NswSerial {
  public:
    void begin(long baudRate);
    void print(const String &message);
    void println(const String &message);
};

#endif
