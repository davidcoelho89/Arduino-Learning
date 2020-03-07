// Read and Write from eeprom memory

// Author: David Coelho
// Last Update: 2016-04-18

// Import Library
#include <EEPROM.h>

// Init Variables
byte EEPROM_value = 0;

// Define Pins
int LED_pin = 3;

// Program Boot (Initialization)
void setup() 
{
  // Set digital pins' modes
  pinMode(LED_pin,OUTPUT);
  
  // Write values at eeprom 
  for (int i = 0; i < 16; i++) 
    EEPROM.write(i, i * i);
}

// Main Loop (repeats indefinitely)
void loop() 
{
  for (int i = 0; i < 16; i++) 
  {
    EEPROM_value = EEPROM.read(i);
    analogWrite(LED_pin, EEPROM_value);
    delay(50);
  }
  delay(1000);
}
