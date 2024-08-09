/* 
 * Project voiceControl
 * Description: Input voice commands 
 * Author: Your Name
 * Date: 
 */

#include "Particle.h"

const char *voiceBuffer[] = //available voice commands stored in an array
    {
 "Turn on the light",      // 1
        "Turn off the light",     // 2
        "Play music",             // 3
        "Pause",                  // 4
        "Next",                   // 5
        "Previous",               // 6
        "Up",                     // 7
        "Down",                   // 8
        "Turn on the TV",         // 9
        "Turn off the TV",        // 10
        "Increase temperature",   // 11
        "Decrease temperature",   // 12
        "What's the time",        // 13
        "Open the door",          // 14
        "Close the door",         // 15
        "Left",                   // 16
        "Right",                  // 17
        "Stop",                   // 18
        "Start",                  // 19
        "Mode 1",                 // 20
        "Mode 2",                 // 21
        "Go"                      // 22
};

SYSTEM_MODE(SEMI_AUTOMATIC);

// SYSTEM_THREAD(ENABLED);

// SerialLogHandler logHandler(LOG_LEVEL_INFO);

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600); //begin UART connection to voice control module
  
  Serial.printf("Hicell system startup...\n");
  delay(1000);
  Serial.printf("\nWaiting for command...\n\n");
}

void loop()
{
  if (Serial1.available()) //continually check if a serial message is available
  {
    char data;
    data = Serial1.read();
    int index = int(data); //integer representative of accepted voice command
    Serial.printf("Hicell: %c %s\n\nIndex: %i\n\n", data, voiceBuffer[data - 1],index);
  }
}