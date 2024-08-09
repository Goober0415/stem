/*
 * Project: accelerometer
 * Description:
 * Author: Your Name
 * Date:
 */

#include "Particle.h"
#include <ADXL345.h>

ADXL345 accel; // create accelerometer object

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(SEMI_AUTOMATIC);

void accelBegin();

// setup() runs once, when the device is first turned on
void setup()
{
  Serial.begin(9600);
  waitFor(Serial.isConnected,10000);

  accelBegin(); //function to startup the accelerometer
}

// loop() runs over and over again, as quickly as it can execute.
void loop()
{
  int x, y, z;
  accel.readXYZ(&x, &y, &z); // read the accelerometer values and store them in variables  x,y,z

  Serial.printf("x: %i, y: %i, z: %i\n", x,y,z);
  double xyz[3];
  double ax, ay, az;
  accel.getAcceleration(xyz);
  ax = xyz[0];
  ay = xyz[1];
  az = xyz[2];

  Serial.printf("ax: %f, ay: %f, az: %f",ax,ay,az);

  delay(500);
}

void accelBegin()
{
  accel.powerOn();

  // set activity/ inactivity thresholds (0-255)
  accel.setActivityThreshold(75);   // 62.5mg per increment
  accel.setInactivityThreshold(75); // 62.5mg per increment
  accel.setTimeInactivity(10);      // how many seconds of no activity is inactive?

  // look of activity movement on this axes - 1 == on; 0 == off
  accel.setActivityX(1);
  accel.setActivityY(1);
  accel.setActivityZ(1);

  // look of inactivity movement on this axes - 1 == on; 0 == off
  accel.setInactivityX(1);
  accel.setInactivityY(1);
  accel.setInactivityZ(1);

  // look of tap movement on this axes - 1 == on; 0 == off
  accel.setTapDetectionOnX(0);
  accel.setTapDetectionOnY(0);
  accel.setTapDetectionOnZ(1);

  // set values for what is a tap, and what is a double tap (0-255)
  accel.setTapThreshold(50);     // 62.5mg per increment
  accel.setTapDuration(15);      // 625us per increment
  accel.setDoubleTapLatency(80); // 1.25ms per increment
  accel.setDoubleTapWindow(200); // 1.25ms per increment

  // set values for what is considered freefall (0-255)
  accel.setFreeFallThreshold(7); //(5 - 9) recommended - 62.5mg per increment
  accel.setFreeFallDuration(45); //(20 - 70) recommended - 5ms per increment

  // setting all interrupts to take place on int pin 1
  // I had issues with int pin 2, was unable to reset it
  accel.setInterruptMapping(ADXL345_INT_SINGLE_TAP_BIT, ADXL345_INT1_PIN);
  accel.setInterruptMapping(ADXL345_INT_DOUBLE_TAP_BIT, ADXL345_INT1_PIN);
  accel.setInterruptMapping(ADXL345_INT_FREE_FALL_BIT, ADXL345_INT1_PIN);
  accel.setInterruptMapping(ADXL345_INT_ACTIVITY_BIT, ADXL345_INT1_PIN);
  accel.setInterruptMapping(ADXL345_INT_INACTIVITY_BIT, ADXL345_INT1_PIN);

  // register interrupt actions - 1 == on; 0 == off
  accel.setInterrupt(ADXL345_INT_SINGLE_TAP_BIT, 1);
  accel.setInterrupt(ADXL345_INT_DOUBLE_TAP_BIT, 1);
  accel.setInterrupt(ADXL345_INT_FREE_FALL_BIT, 1);
  accel.setInterrupt(ADXL345_INT_ACTIVITY_BIT, 1);
  accel.setInterrupt(ADXL345_INT_INACTIVITY_BIT, 1);
}