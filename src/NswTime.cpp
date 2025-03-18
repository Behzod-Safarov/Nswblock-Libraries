#include "NswTime.h"

void NswTime::begin() {
    Wire.begin();
}

void NswTime::setTime(uint8_t sec, uint8_t min, uint8_t hour) {
    Wire.beginTransmission(DS3231_ADDRESS);
    Wire.write(0x00); // Start at seconds register
    Wire.write(decToBcd(sec));
    Wire.write(decToBcd(min));
    Wire.write(decToBcd(hour));
    Wire.endTransmission();
}

void NswTime::setDate(uint8_t day, uint8_t date, uint8_t month, uint8_t year) {
    Wire.beginTransmission(DS3231_ADDRESS);
    Wire.write(0x03); // Start at day register
    Wire.write(decToBcd(day));
    Wire.write(decToBcd(date));
    Wire.write(decToBcd(month));
    Wire.write(decToBcd(year));
    Wire.endTransmission();
}

String NswTime::getTime() {
    Wire.beginTransmission(DS3231_ADDRESS);
    Wire.write(0x00); // Start at seconds register
    Wire.endTransmission();
    Wire.requestFrom(DS3231_ADDRESS, 3);

    uint8_t sec = bcdToDec(Wire.read());
    uint8_t min = bcdToDec(Wire.read());
    uint8_t hour = bcdToDec(Wire.read());

    char buffer[9];
    snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", hour, min, sec);
    return String(buffer);
}

String NswTime::getDate() {
    Wire.beginTransmission(DS3231_ADDRESS);
    Wire.write(0x03); // Start at day register
    Wire.endTransmission();
    Wire.requestFrom(DS3231_ADDRESS, 4);

    uint8_t day = bcdToDec(Wire.read());
    uint8_t date = bcdToDec(Wire.read());
    uint8_t month = bcdToDec(Wire.read());
    uint8_t year = bcdToDec(Wire.read());

    char buffer[11];
    snprintf(buffer, sizeof(buffer), "%02d/%02d/20%02d", date, month, year);
    return String(buffer);
}

uint8_t NswTime::decToBcd(uint8_t val) {
    return ((val / 10 * 16) + (val % 10));
}

uint8_t NswTime::bcdToDec(uint8_t val) {
    return ((val / 16 * 10) + (val % 16));
}
