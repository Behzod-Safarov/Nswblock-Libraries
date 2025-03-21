#include "NswOledDisplay.h"

// Constructor: Initializes the display object
NswOledDisplay::NswOledDisplay() : display(OLED_WIDTH, OLED_HEIGHT, &Wire, -1) {}

// Initialize the OLED display
bool NswOledDisplay::begin() {
    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDRESS)) {
        return false;  // Initialization failed
    }
    display.clearDisplay();
    display.display();
    return true;  // Success
}

// Clear the display
void NswOledDisplay::clear() {
    display.clearDisplay();
}

// Print text at a specific position
void NswOledDisplay::printText(const char* text, int x, int y, int size) {
    display.setTextSize(size);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(x, y);
    display.println(text);
}

// Print a number at a specific position
void NswOledDisplay::printNumber(int number, int x, int y, int size) {
    display.setTextSize(size);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(x, y);
    display.println(number);
}

// Update the screen with new content
void NswOledDisplay::show() {
    display.display();
}
