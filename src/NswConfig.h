 #ifndef NswConfig_H
 #define NswConfig_H
 
 #include <utility/Servo.h>
 #include <utility/Wire.h>
 #include <utility/EEPROM.h>
 #include <utility/SoftwareSerial.h>
 #include <utility/SPI.h>
 
 #define Nsw_PORT_DEFINED
 
 #if defined(__AVR__)
 #define NswPIN_TO_BASEREG(pin)               ( portInputRegister (digitalPinToPort (pin) ) )
 #define NswPIN_TO_BITMASK(pin)               ( digitalPinToBitMask (pin) )
 #define NswIO_REG_TYPE                       uint8_t
 #define NswIO_REG_ASM                        asm ("r30")
 #define NswDIRECT_READ(base, mask)           ( ( (*(base) ) & (mask) ) ? 1 : 0)
 #define NswDIRECT_MODE_INPUT(base, mask)     ( (*( (base) + 1) ) &= ~(mask) ), ( (*( (base) + 2) ) |= (mask) ) // INPUT_PULLUP
 #define NswDIRECT_MODE_OUTPUT(base, mask)    ( (*( (base) + 1) ) |= (mask) )
 #define NswDIRECT_WRITE_LOW(base, mask)      ( (*( (base) + 2) ) &= ~(mask) )
 #define NswDIRECT_WRITE_HIGH(base, mask)     ( (*( (base) + 2) ) |= (mask) )
 #endif // __AVR__
 
 #endif // NswConfig_H