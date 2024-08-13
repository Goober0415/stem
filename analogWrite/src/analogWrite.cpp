/* 
 * Project analogWrite
 * Description: Use analogWrite to change the brightness of an LED
 * Author: Jamie Gavina
 * Date: 8/13/2024
 */

#include "Particle.h"

const int LED = D4;

SYSTEM_MODE(SEMI_AUTOMATIC);

// setup() runs once, when the device is first turned on
void setup() {
  pinMode(LED, OUTPUT);

  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);

  //analog write here
  analogWrite(LED, 16);
  
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {

  for(int i = 0; i <= 255; i++)
  {

    analogWrite(LED, i + 1);
    delay(10);
    

  }
  for(int i = 0; i >= 0; i--)
  {
    analogWrite(LED, i - 1);
    delay(10);
  }
  

}
