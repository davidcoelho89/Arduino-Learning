// Wait a given time, without stoping other functions

// Author: David Coelho
// Last Update: 2016-04-18

// Init Variables

int ledState = LOW; // LED's last 

unsigned long previous_ms = 0; // last time LED was updated
unsigned long current_ms = 0; // current time
unsigned long interval_ms = 1000; // interval at which to blink

// Define Pins

int ledPin =  13;

// Program Boot
void setup() 
{
  // Set the digital pin mode as output:
  pinMode(ledPin, OUTPUT);
}

// Main Loop
void loop()
{
  // Get current time in ms or us
  current_ms = millis();
  //current_us = micros();

  // Main Function
  if(current_ms - previous_ms >= interval_ms) 
  {
    // save the last time the led state was changed 
    previous_ms = current_ms;   

    // Changes led state
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // set the LED with the new state
    digitalWrite(ledPin, ledState);
  }
}

