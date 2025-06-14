#include "NswLineFollower.h"

NswLineFollower::NswLineFollower() {
  _sensor1 = 0;
  _sensor2 = 0;
}

NswLineFollower::NswLineFollower(const NswPort &port) {
  _sensor1 = port.pin1;
  _sensor2 = port.pin2;
  pinMode(_sensor1, INPUT);
  pinMode(_sensor2, INPUT);
}

NswLineFollower::NswLineFollower(uint8_t sensor1, uint8_t sensor2) {
  _sensor1 = sensor1;
  _sensor2 = sensor2;
  pinMode(_sensor1, INPUT);
  pinMode(_sensor2, INPUT);
}

void NswLineFollower::setpin(uint8_t sensor1, uint8_t sensor2) {
  _sensor1 = sensor1;
  _sensor2 = sensor2;
  pinMode(_sensor1, INPUT);
  pinMode(_sensor2, INPUT);
}

uint8_t NswLineFollower::readSensors(void) {
  bool s1 = digitalRead(_sensor1);
  bool s2 = digitalRead(_sensor2);
  return ((s1 << 1) | s2);
}

bool NswLineFollower::readSensor1(void) {
  return digitalRead(_sensor1);
}

bool NswLineFollower::readSensor2(void) {
  return digitalRead(_sensor2);
}
