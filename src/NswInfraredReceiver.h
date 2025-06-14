
#ifndef _NSW_INFRARED_RECEIVER_H_
#define _NSW_INFRARED_RECEIVER_H_

#include <Arduino.h>
#include <SoftwareSerial.h>
#include "NSWPort.h"


#define IR_BUTTON_A         (0x45)
#define IR_BUTTON_B         (0x46)
#define IR_BUTTON_C         (0x47)
#define IR_BUTTON_E         (0x43)
#define IR_BUTTON_D         (0x44)
#define IR_BUTTON_UP        (0x40)
#define IR_BUTTON_E         (0x43)
#define IR_BUTTON_LEFT      (0x07)
#define IR_BUTTON_SETTING   (0x15)
#define IR_BUTTON_RIGHT     (0x09)
#define IR_BUTTON_DOWN      (0x19)
#define IR_BUTTON_F     (0xD)
#define IR_BUTTON_0     (0x16)
#define IR_BUTTON_1     (0x0C)
#define IR_BUTTON_2     (0x18)
#define IR_BUTTON_3     (0x5E)
#define IR_BUTTON_4     (0x08)
#define IR_BUTTON_5     (0x1C)
#define IR_BUTTON_6     (0x5A)
#define IR_BUTTON_7     (0x42)
#define IR_BUTTON_8     (0x52)
#define IR_BUTTON_9     (0x4A)

#define NSW_PORT_DEFINED // Enable port-based initialization

class NSWInfraredReceiver {
public:
#ifdef NSW_PORT_DEFINED
  // Constructor for NSWbloc port mapping
  NSWInfraredReceiver(Port port);
#else
  // Constructor for custom pin assignment
  NSWInfraredReceiver(uint8_t receivePin, uint8_t keyCheckPin, bool inverse_logic = false);
#endif

  void begin(void);
  int16_t read(void);
  bool buttonState(void);
  uint8_t getCode(void);
  void loop(void);

private:
  SoftwareSerial _serial; // SoftwareSerial for IR communication
  uint8_t _rxPin;        // Receive pin for IR data
  uint8_t _keyCheckPin;  // Pin for button state checking
  bool _inverseLogic;    // Serial logic inversion flag
  uint8_t _irCode;       // Current IR code
  uint8_t _preIrCode;    // Previous IR code for filtering
};

#endif // _NSW_INFRARED_RECEIVER_H_