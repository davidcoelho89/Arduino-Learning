// Gerenal Example of analog IOs

// Author: David Coelho
// Last Update: 2016-04-18

// Define Pins
int POT_pin = 0; // Analog/read pins are from 0 to 5 (UNO)
int LED_pin = 3; // Analog/PWM pins are 3, 5, 6, 9, 10, 11 (UNO)

// Init Variables
int POT_value = 0; // current value of potentiometer
int LED_duty_cicle = 0; // current value of PWM duty cicle 

// Program Boot (Initialization)
void setup()
{
  // Set digital pins' modes
  pinMode(LED_pin,OUTPUT); //this will be used as a PWM
}

// Main Loop (repeats indefinitely)
void loop()
{
  // Get current value of potentiometer
  POT_value = analogRead(POT_pin); // from 0 to 1023

  // Set PWM duty cicle
  LED_duty_cicle = POT_value / 4; // from 0 to 255

  // Update PWM duty cicle
  analogWrite(LED_pin, LED_duty_cicle);
  
  // Wait 0.5s
  delay(500);
}
