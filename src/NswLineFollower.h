#ifndef NSW_LINE_FOLLOWER_H
#define NSW_LINE_FOLLOWER_H

#include <Arduino.h>
#include "NswPort.h"  // NSWbloc port defines

#define S1_IN_S2_IN   (0x00)
#define S1_IN_S2_OUT  (0x01)
#define S1_OUT_S2_IN  (0x02)
#define S1_OUT_S2_OUT (0x03)

class NswLineFollower {
public:
  NswLineFollower();
  NswLineFollower(const NswPort &port);
  NswLineFollower(uint8_t sensor1, uint8_t sensor2);

  void setpin(uint8_t sensor1, uint8_t sensor2);
  uint8_t readSensors(void);
  bool readSensor1(void);
  bool readSensor2(void);

private:
  uint8_t _sensor1;
  uint8_t _sensor2;
};

#endif
