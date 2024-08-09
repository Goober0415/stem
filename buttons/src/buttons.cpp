/* 
 * Project buttons
 * Description: Button reading and control.
 * Author: Your Name
 * Date: 
 */

// Include Particle Device OS APIs
#include "Particle.h"

const int LED = D4;
const int BUTTON = A0;

bool buttonState; //a bool represents true or false

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(SEMI_AUTOMATIC);

// setup() runs once, when the device is first turned on
void setup() {
  
  //setup serial monitor here

  //add pinModes for your LED and Button here
  
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {

  buttonState = digitalRead(BUTTON);

}
