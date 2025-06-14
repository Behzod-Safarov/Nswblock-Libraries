#ifndef NSW_RGB_LED_H
#define NSW_RGB_LED_H

#include <Arduino.h>
#include <utility/RGBLed/Adafruit_NeoPixel.h>
#include "NswPort.h"

#define LED_COUNT 4  // Set to 4 LEDs

// Define color order options
enum class ColorOrder {
  GRB,  // Default WS2812B order
  RGB,
  BRG,
  RBG,
  GBR,
  BGR
};

class NswRGBLed {
public:
  NswRGBLed(Port port, ColorOrder order = ColorOrder::GRB);
  void begin();
  void clear();
  void setBrightness(uint8_t level);
  void setColor(uint8_t red, uint8_t green, uint8_t blue);
  void setColor(uint8_t index, uint8_t red, uint8_t green, uint8_t blue);
  void show();

private:
  uint8_t _pin;
  uint8_t _brightness;
  ColorOrder _colorOrder;
  Adafruit_NeoPixel _strip;  // NeoPixel object
  uint32_t getNeoPixelType(ColorOrder order);  // Helper to map ColorOrder
};

#endif