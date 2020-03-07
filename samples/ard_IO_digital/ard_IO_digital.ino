// Gerenal Example of digital IOs

// Author: David Coelho
// Last Update: 2016-04-18

// Init Variables
int BOT1_state = 0;

// Define pins
int LED1_pin = 3;
int BOT1_pin = 4;

// Program Boot (Initialization)
void setup()
{
  // Set digital pins' modes
  pinMode(LED1_pin,OUTPUT);
  pinMode(BOT1_pin,INPUT_PULLUP);
}

// Main Loop (repeats indefinitely)
void loop()
{
  // Read Button
  BOT1_state = digitalRead(BOT1_pin);
  
  // blink led slowly
  if (BOT1_state == HIGH)
  {
    digitalWrite(LED1_pin, HIGH);
    delay(2000);
    digitalWrite(LED1_pin, LOW);
    delay(2000);
  }
  
  else // blik led quickly
  {
    digitalWrite(LED1_pin, HIGH);
    delay(400);
    digitalWrite(LED1_pin, LOW);
    delay(400);
  }
}
