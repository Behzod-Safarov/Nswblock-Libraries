/* Includes ------------------------------------------------------------------*/
#include <Arduino.h>
#include "NswColorSensor.h"

// Default I2C address (0x38)
NswColorSensor colorSensor;

void setup() {
  Serial.begin(9600);
  delay(1000);
  colorSensor.begin();
  Serial.print("Sensor ID: 0x");
  Serial.println(colorSensor.reportId(), HEX);
  Serial.println("Color Sensor Initialized");
}

void loop() {
  colorSensor.readColorData();
  Serial.print("Raw Red: "); Serial.print(colorSensor.getRedData());
  Serial.print(" | Green: "); Serial.print(colorSensor.getGreenData());
  Serial.print(" | Blue: "); Serial.print(colorSensor.getBlueData());
  Serial.print(" | Clear: "); Serial.println(colorSensor.getClearData());

  uint8_t color = colorSensor.identifyColor();
  Serial.print("Detected Color (identifyColor): ");
  switch (color) {
    case NSW_WHITE:  Serial.println("White"); break;
    case NSW_PINKE:  Serial.println("Pinke"); break;
    case NSW_RED:    Serial.println("Red"); break;
    case NSW_ORANGE: Serial.println("Orange"); break;
    case NSW_YELLOW: Serial.println("Yellow"); break;
    case NSW_GREEN:  Serial.println("Green"); break;
    case NSW_CYAN:   Serial.println("Cyan"); break;
    case NSW_BLUE:   Serial.println("Blue"); break;
    case NSW_PURPLE: Serial.println("Purple"); break;
    case NSW_BLACK:  Serial.println("Black"); break;
    case NSW_GOLD:   Serial.println("Gold"); break;
    default:         Serial.println("Unknown"); break;
  }

  uint8_t result = colorSensor.getResult();
  Serial.print("Detected Color (getResult): ");
  switch (result) {
    case NSW_WHITE:  Serial.println("White"); break;
    case NSW_PINKE:  Serial.println("Pinke"); break;
    case NSW_RED:    Serial.println("Red"); break;
    case NSW_ORANGE: Serial.println("Orange"); break;
    case NSW_YELLOW: Serial.println("Yellow"); break;
    case NSW_GREEN:  Serial.println("Green"); break;
    case NSW_CYAN:   Serial.println("Cyan"); break;
    case NSW_BLUE:   Serial.println("Blue"); break;
    case NSW_PURPLE: Serial.println("Purple"); break;
    case NSW_BLACK:  Serial.println("Black"); break;
    case NSW_GOLD:   Serial.println("Gold"); break;
    default:         Serial.println("Unknown"); break;
  }

  Serial.println("---");
  delay(1000);
}