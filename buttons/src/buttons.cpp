/* 
 * Project buttons
 * Description: Button reading and control.
 * Author: Jamie Gavina
 * Date: 08/13/2024
 */

// Include Particle Device OS APIs
#include "Particle.h"

const int LED = D4;
const int BUTTON = A2;

bool buttonState; //a bool represents true or false

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(SEMI_AUTOMATIC);

// setup() runs once, when the device is first turned on
void setup() {
  
  //setup serial monitor here
Serial.begin(9600);
waitFor(Serial.isConnected, 10000);

Serial.printf("Ready to go... \n");

  //add pinModes for your LED and Button here
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {

  buttonState = digitalRead(BUTTON);
  Serial.printf("Button state: %i",buttonState);

  if(buttonState == true) {
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW);
  }

}
