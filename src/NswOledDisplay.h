#ifndef NSW_OLED_DISPLAY_H
#define NSW_OLED_DISPLAY_H

#include <Arduino.h>
#include <Wire.h>
#include "NswPort.h"

#define OLED_WIDTH 128
#define OLED_HEIGHT 64
#define OLED_PAGES (OLED_HEIGHT / 8)
#define OLED_I2C_ADDRESS 0x3C

#define OLED_COLOR_WHITE true
#define OLED_COLOR_BLACK false

class NswOledDisplay {
public:
    NswOledDisplay(Port port);
    bool begin();  
    void clear();
    void display();
    
    void setTextSize(uint8_t size);
    void setCursor(uint8_t x, uint8_t y);
    void print(const char* text);
    void print(int number);
    void print(float number, uint8_t decimalPlaces = 2);
    void println(const char* text);
    void println(int number);
    void println(unsigned long number);
    void println(float number, uint8_t decimalPlaces = 2);
    
    void drawPixel(uint8_t x, uint8_t y, bool color = OLED_COLOR_WHITE);
    void drawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, bool color = OLED_COLOR_WHITE);
    void drawRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, bool color = OLED_COLOR_WHITE);
    void fillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, bool color = OLED_COLOR_WHITE);
    void drawCircle(uint8_t x0, uint8_t y0, uint8_t r, bool color = OLED_COLOR_WHITE);
    void fillCircle(uint8_t x0, uint8_t y0, uint8_t r, bool color = OLED_COLOR_WHITE);
    void drawTriangle(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, bool color = OLED_COLOR_WHITE);
    void fillTriangle(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, bool color = OLED_COLOR_WHITE);
    
    void drawBitmap(uint8_t x, uint8_t y, const uint8_t* bitmap, uint8_t w, uint8_t h, bool color = OLED_COLOR_WHITE);
    
    void invertDisplay(bool invert);
    void setContrast(uint8_t contrast);
    void setRotation(uint8_t rotation);
    void sleep(bool enable);
    void powerSave(bool enable);

private:
    uint8_t _sclPin;
    uint8_t _sdaPin;
    uint8_t _framebuffer[OLED_WIDTH * OLED_PAGES];
    
    uint8_t _cursorX;
    uint8_t _cursorY;
    uint8_t _textSize;
    uint8_t _rotation;
    
    static const uint8_t _font[] PROGMEM;
    static const uint8_t _fontWidth;
    static const uint8_t _fontHeight;
    
    void sendCommand(uint8_t cmd);
    void sendCommands(const uint8_t *cmds, uint8_t len);
    void sendData(const uint8_t* data, uint16_t len);
    void drawChar(uint8_t x, uint8_t y, char c, bool color = OLED_COLOR_WHITE);
    inline void transformCoordinates(uint8_t& x, uint8_t& y);
    void swap(int16_t& a, int16_t& b);
};

#endif // NSW_OLED_DISPLAY_H