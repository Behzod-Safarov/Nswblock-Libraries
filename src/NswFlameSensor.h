/**
 * \par Copyright (C), 2023, Adapted for NswPort
 * \class NswFlameSensor
 * \brief   Driver for flame sensor using NswPort.
 * @file    NswFlameSensor.h
 * @author  Adapted
 * @version V1.0.0
 * @date    2023/10/27
 * @brief   Header for NswFlameSensor.cpp module
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
#ifndef NswFlameSensor_H
#define NswFlameSensor_H

#include <Arduino.h>
#include "NswPort.h" 
/**
 * Class: NswFlameSensor
 * \par Description
 * Declaration of Class NswFlameSensor.
 */
class NswFlameSensor
{
public:
/**
 * Constructor which initializes the flame sensor on the specified NswPort,
 * using pin2 for analog input and pin1 for digital input.
 * \param[in]
 *   port - A Port enum value representing the RJ25 port
 */
  NswFlameSensor(Port port);

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
  void begin(void);

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
  int readAnalog(void);

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
  bool readDigital(void);

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
  bool isFlameDetected(int threshold);

private:
  uint8_t analogPin;  // Pin for analog signal (pin2)
  uint8_t digitalPin; // Pin for digital signal (pin1)
};

#endif