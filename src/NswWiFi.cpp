#include "NswWiFi.h"

NswWiFi::NswWiFi(Port port) : SoftwareSerial(0, 0) { // Temporary pins
    NswPort selectedPort(port);
    uint8_t rxPin = selectedPort.pin1;
    uint8_t txPin = selectedPort.pin2;

    SoftwareSerial::begin(115200);  // Initialize SoftwareSerial with the default baud rate
    SoftwareSerial::end();          // End it to reinitialize with correct pins

    // Reconstruct SoftwareSerial with the correct pins
    *((uint8_t*)this) = rxPin;
    *((uint8_t*)this + 1) = txPin;
}

void NswWiFi::begin(long baudRate) {
    SoftwareSerial::begin(baudRate);
    delay(1000);
    Serial.println("WiFi module initialized!");
}

bool NswWiFi::connectWiFi(const char* ssid, const char* password) {
    println("AT+CWJAP=\"" + String(ssid) + "\",\"" + String(password) + "\"");
    delay(5000);
    return find("OK");
}

bool NswWiFi::isConnected() {
    println("AT+CIPSTATUS");
    delay(1000);
    return find("STATUS:2");
}

String NswWiFi::getIP() {
    println("AT+CIFSR");
    delay(1000);
    String ip;
    while (available()) {
        char c = read();
        ip += c;
    }
    return ip;
}
