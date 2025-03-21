/* 📌 Kutubxonalarni chaqiramiz */
#include <Arduino.h>
#include "NswColorSensor.h"

// 📌 Rang sensorini standart I2C adres bilan ishga tushiramiz (0x38)
NswColorSensor colorSensor;

void setup() {
  Serial.begin(9600);  // 📌 Serial portni ishga tushiramiz
  delay(1000);         // 📌 Sensor ishga tushishi uchun kutish

  colorSensor.begin(); // 📌 Sensor ishga tushiriladi

  Serial.print("Sensor ID: 0x");
  Serial.println(colorSensor.reportId(), HEX);
  Serial.println("Color Sensor Ishga Tushdi!");
}

void loop() {
  // 📌 Rang ma'lumotlarini o‘qib olamiz
  colorSensor.readColorData();

  // 📌 RGB va Clear (yorug‘lik darajasi) qiymatlarini chiqaramiz
  Serial.print("Raw Red: "); Serial.print(colorSensor.getRedData());
  Serial.print(" | Green: "); Serial.print(colorSensor.getGreenData());
  Serial.print(" | Blue: "); Serial.print(colorSensor.getBlueData());
  Serial.print(" | Clear: "); Serial.println(colorSensor.getClearData());

  // 📌 Sensor tomonidan aniqlangan rangni chiqaramiz
  uint8_t color = colorSensor.identifyColor();
  Serial.print("Aniqlangan rang (identifyColor): ");
  switch (color) {
    case NSW_WHITE:  Serial.println("Oq (White)"); break;
    case NSW_PINKE:  Serial.println("Pushti (Pink)"); break;
    case NSW_RED:    Serial.println("Qizil (Red)"); break;
    case NSW_ORANGE: Serial.println("To‘q sariq (Orange)"); break;
    case NSW_YELLOW: Serial.println("Sariq (Yellow)"); break;
    case NSW_GREEN:  Serial.println("Yashil (Green)"); break;
    case NSW_CYAN:   Serial.println("Ko‘kimtir (Cyan)"); break;
    case NSW_BLUE:   Serial.println("Ko‘k (Blue)"); break;
    case NSW_PURPLE: Serial.println("Binafsha (Purple)"); break;
    case NSW_BLACK:  Serial.println("Qora (Black)"); break;
    case NSW_GOLD:   Serial.println("Tilla (Gold)"); break;
    default:         Serial.println("Noma'lum rang"); break;
  }

  // 📌 getResult() bilan aniqlangan rangni chiqaramiz
  uint8_t result = colorSensor.getResult();
  Serial.print("Aniqlangan rang (getResult): ");
  switch (result) {
    case NSW_WHITE:  Serial.println("Oq (White)"); break;
    case NSW_PINKE:  Serial.println("Pushti (Pink)"); break;
    case NSW_RED:    Serial.println("Qizil (Red)"); break;
    case NSW_ORANGE: Serial.println("To‘q sariq (Orange)"); break;
    case NSW_YELLOW: Serial.println("Sariq (Yellow)"); break;
    case NSW_GREEN:  Serial.println("Yashil (Green)"); break;
    case NSW_CYAN:   Serial.println("Ko‘kimtir (Cyan)"); break;
    case NSW_BLUE:   Serial.println("Ko‘k (Blue)"); break;
    case NSW_PURPLE: Serial.println("Binafsha (Purple)"); break;
    case NSW_BLACK:  Serial.println("Qora (Black)"); break;
    case NSW_GOLD:   Serial.println("Tilla (Gold)"); break;
    default:         Serial.println("Noma'lum rang"); break;
  }

  Serial.println("---");
  delay(1000);  // 📌 Keyingi o‘lchovga tayyorgarlik
}
