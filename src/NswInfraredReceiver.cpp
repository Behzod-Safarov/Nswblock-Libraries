/**
 * \par Copyright (C), 2025, YourName
 * @file NSWInfraredReceiver.cpp
 * @author YourName
 * @version V1.0.0
 * @date 2025/06/14
 * @brief Driver for NSWbloc Infrared Receiver device.
 *
 * \par Copyright
 * This software is Copyright (C), 2025, YourName. Use is subject to license
 * conditions. The main licensing options available are GPL V2 or Commercial.
 */

#include "NSWInfraredReceiver.h"

#ifdef NSW_PORT_DEFINED
/**
 * \par Function
 *   Constructor
 * \par Description
 *   Initializes the NSWInfraredReceiver with a specific NSWbloc port.
 * \param[in]
 *   port - NSWbloc port (e.g., PORT_1, PORT_2, etc.)
 */
NSWInfraredReceiver::NSWInfraredReceiver(Port port) : _serial(0, 255) // Dummy TX pin
{
  NswPort nswPort(port);
  _keyCheckPin = nswPort.pin1; // pin1 for key check (like s1)
  _rxPin = nswPort.pin2;       // pin2 for RX (like s2)
  _inverseLogic = false;
  _serial = SoftwareSerial(_rxPin, 255); // Reinitialize with correct RX pin
}
#else
/**
 * \par Function
 *   Constructor
 * \par Description
 *   Initializes the NSWInfraredReceiver with custom RX and key check pins.
 * \param[in]
 *   receivePin - The RX pin for IR data
 * \param[in]
 *   keyCheckPin - The pin for checking button state
 * \param[in]
 *   inverse_logic - Whether serial logic is inverted
 */
NSWInfraredReceiver::NSWInfraredReceiver(uint8_t receivePin, uint8_t keyCheckPin, bool inverse_logic)
    : _serial(receivePin, 255), _inverseLogic(inverse_logic)
{
  _rxPin = receivePin;
  _keyCheckPin = keyCheckPin;
}
#endif

/**
 * \par Function
 *   begin
 * \par Description
 *   Initializes serial communication at 9600 baud and sets up the key check pin.
 * \par Output
 *   None
 * \return
 *   None
 */
void NSWInfraredReceiver::begin(void) {
  _serial.begin(9600);
  pinMode(_keyCheckPin, INPUT);
  _irCode = 0;
  _preIrCode = 0;
}

/**
 * \par Function
 *   read
 * \par Description
 *   Reads a character from the IR receiver's serial port.
 * \par Output
 *   None
 * \return
 *   The character read, or -1 if none is available
 */
int16_t NSWInfraredReceiver::read(void) {
  int16_t val = _serial.read();
  val &= 0xff; // Mask to 8 bits
  return val;
}

/**
 * \par Function
 *   buttonState
 * \par Description
 *   Checks the state of the button (key check pin).
 * \par Output
 *   None
 * \return
 *   true if button is pressed, false otherwise
 */
bool NSWInfraredReceiver::buttonState(void) {
  bool val = digitalRead(_keyCheckPin);
  return !val; // Active low, similar to MeInfraredReceiver
}

/**
 * \par Function
 *   getCode
 * \par Description
 *   Returns the last valid IR code received.
 * \par Output
 *   None
 * \return
 *   The IR code as a uint8_t
 */
uint8_t NSWInfraredReceiver::getCode(void) {
  return _irCode;
}

/**
 * \par Function
 *   loop
 * \par Description
 *   Processes IR data when the button is pressed, filters out invalid codes.
 * \par Output
 *   None
 * \return
 *   None
 */
void NSWInfraredReceiver::loop(void) {
  if (buttonState()) {
    if (_serial.available() > 0) {
      int r = read();
      if (r < 0xff) {
        if (r == 0) {
          _irCode = _preIrCode; // Use previous code if 0 is received
        } else {
          _irCode = r;
          _preIrCode = _irCode; // Store current code as previous
        }
      }
    }
  } else {
    _irCode = 0;
    _preIrCode = 0;
  }
}