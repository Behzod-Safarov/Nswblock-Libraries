#ifndef NSW_OLED_DISPLAY_H
#define NSW_OLED_DISPLAY_H

#include <Wire.h>                // I2C communication
#include <Adafruit_GFX.h>        // Graphics library
#include <Adafruit_SSD1306.h>    // OLED display library

#define OLED_WIDTH 128           // OLED width in pixels
#define OLED_HEIGHT 64           // OLED height in pixels
#define OLED_I2C_ADDRESS 0x3C    // Default I2C address for SSD1306

class NswOledDisplay {
public:
    NswOledDisplay();  // Constructor
    bool begin();      // Initialize display
    void clear();      // Clear the screen
    void printText(const char* text, int x = 0, int y = 0, int size = 1);  
    void printNumber(int number, int x = 0, int y = 0, int size = 1);
    void show();       // Update display

private:
    Adafruit_SSD1306 display; // OLED display object
};

#endif
