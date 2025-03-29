/**
 * \par Copyright (C), 2023, Adapted for NswPort
 * \class NswFlameSensor
 * \brief   Driver for flame sensor using NswPort.
 * @file    NswFlameSensor.cpp
 * @author  Adapted
 * @version V1.0.0
 * @date    2023/10/27
 * @brief   Driver for NswFlameSensor module
 *
 * \par Copyright
 * This software is Copyright (C), 2023. Use is subject to license conditions.
 * The main licensing options available are GPL V3 or Commercial.
 *
 * \par Open Source Licensing GPL V3
 * This is the appropriate option if you want to share the source code of your 
 * application with everyone you distribute it to, and you also want to give them 
 * the right to share who uses it. If you wish to use this software under Open 
 * Source Licensing, you must contribute all your source code to the open source 
 * community in accordance with the GPL Version 3 when your application is 
 * distributed. See http://www.gnu.org/copyleft/gpl.html
 *
 * \par Description
 * This file is a driver for a flame sensor, providing analog and digital readings 
 * using the NswPort class for pin management.
 *
 * \par Method List:
 *
 *    1. void NswFlameSensor::begin(void)
 *    2. int NswFlameSensor::readAnalog(void)
 *    3. bool NswFlameSensor::readDigital(void)
 *    4. bool NswFlameSensor::isFlameDetected(int threshold)
 *
 * \par History:
 * <pre>
 * `<Author>`         `<Time>`        `<Version>`        `<Descr>`
 * Adapted           2023/10/27       1.0.0            Initial creation for NswPort
 * </pre>
 */
#include "NswFlameSensor.h"
#include "NswPort.h"  // Included here for implementation

/**
 * Constructor which initializes the flame sensor on the specified NswPort,
 * using pin2 for analog input and pin1 for digital input.
 * \param[in]
 *   port - A Port enum value representing the RJ25 port
 */
NswFlameSensor::NswFlameSensor(Port port) {
  NswPort p(port);  // Create NswPort object
  analogPin = p.pin2;   // Analog signal on pin2
  digitalPin = p.pin1;  // Digital signal on pin1
}

/**
 * \par Function
 *   begin
 * \par Description
 *   Initialize the flame sensor pins.
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
void NswFlameSensor::begin(void) {
  pinMode(analogPin, INPUT);
  pinMode(digitalPin, INPUT);
}

/**
 * \par Function
 *   readAnalog
 * \par Description
 *   Read the analog value from the flame sensor (0-1023).
 * \par Output
 *   None
 * \return
 *   The analog reading from the sensor
 * \par Others
 *   None
 */
int NswFlameSensor::readAnalog(void) {
  return analogRead(analogPin);
}

/**
 * \par Function
 *   readDigital
 * \par Description
 *   Read the digital value from the flame sensor (HIGH/LOW).
 * \par Output
 *   None
 * \return
 *   True if flame detected (LOW), false otherwise (HIGH)
 * \par Others
 *   None
 */
bool NswFlameSensor::readDigital(void) {
  return !digitalRead(digitalPin);  // LOW means flame detected (active low)
}

/**
 * \par Function
 *   isFlameDetected
 * \par Description
 *   Check if a flame is detected based on an analog threshold.
 * \param[in]
 *   threshold - The analog value (0-1023) below which a flame is detected
 * \par Output
 *   None
 * \return
 *   True if flame detected (analog value < threshold), false otherwise
 * \par Others
 *   None
 */
bool NswFlameSensor::isFlameDetected(int threshold) {
  return analogRead(analogPin) < threshold;  // Lower values indicate stronger flame
}