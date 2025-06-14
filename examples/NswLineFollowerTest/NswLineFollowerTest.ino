#include "NswLineFollower.h"

// NSWbloc’ning PORT_3 ga ulangan deb faraz qilamiz
NswLineFollower lineFinder(PORT_3); 

void setup() {
  Serial.begin(9600);
  Serial.println("NSW Line Follower Test boshlandi");
}

void loop() {
  int sensorState = lineFinder.readSensors();
  switch (sensorState) {
    case S1_IN_S2_IN:
      Serial.println("Sensor 1 va 2 qora chiziqda (ichkarida)");
      break;
    case S1_IN_S2_OUT:
      Serial.println("Sensor 2 oq fon (tashqarida)");
      break;
    case S1_OUT_S2_IN:
      Serial.println("Sensor 1 oq fon (tashqarida)");
      break;
    case S1_OUT_S2_OUT:
      Serial.println("Sensor 1 va 2 oq fonda (tashqarida)");
      break;
    default:
      Serial.println("Noma’lum holat");
      break;
  }
  delay(200);
}
