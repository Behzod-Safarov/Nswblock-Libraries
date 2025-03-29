#ifndef NSW_WIFI_H
#define NSW_WIFI_H

#include <Arduino.h>
#include <utility/SoftwareSerial.h>
#include "NswPort.h"

class NswWiFi : public SoftwareSerial {
public:
    NswWiFi(Port port); // Constructor with port selection
    void begin(long baudRate = 115200);
    bool connectWiFi(const char* ssid, const char* password);
    bool isConnected();
    String getIP();
};

#endif // NSW_WIFI_H
