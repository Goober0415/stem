/* 
 * Project: potentiometers
 * Description: 
 * Author: Your Name
 * Date: 
 */

// Include Particle Device OS APIs
#include "Particle.h"
#include "neopixel.h"

const int POTPIN = A4;

const int PIXELPIN = D2;
const int PIXELCOUNT = 16;
Adafruit_NeoPixel pixel(PIXELCOUNT, PIXELPIN, WS2812B);


int currentPosition; //use these variables to keep track of position
int previousPosition;

SYSTEM_MODE(SEMI_AUTOMATIC);

// setup() runs once, when the device is first turned on
void setup() {
  Serial.begin(9600);
  waitFor(Serial.isConnected, 10000);

  pinMode(POTPIN, INPUT);

  pixel.begin(); 
  pixel.setBrightness(100);
  pixel.setPixelColor(0, 0x0000FF);

  Serial.printf("Setup complete...\n");
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  currentPosition = analogRead(POTPIN);

  //your code will likely go here
}
