#ifndef NSW_TIME_H
#define NSW_TIME_H

#include <Wire.h>

#define DS3231_ADDRESS 0x68  // I2C address of DS3231 RTC

class NswTime {
public:
    void begin();
    void setTime(uint8_t sec, uint8_t min, uint8_t hour);
    void setDate(uint8_t day, uint8_t date, uint8_t month, uint8_t year);
    String getTime();
    String getDate();

private:
    uint8_t decToBcd(uint8_t val);
    uint8_t bcdToDec(uint8_t val);
};

#endif // NSW_TIME_H
