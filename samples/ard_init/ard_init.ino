// Arduino First Sample

// Author: David Coelho
// Last Update: 2016-04-18

// Program Boot (Initialization)
void setup() 
{
  // Set digital pins' modes
  pinMode(13, OUTPUT);
}

// Main Loop (repeats indefinitely)
void loop() 
{
  digitalWrite(13, HIGH);
  
  delay(1000); // wait 1s (1000 ms)
  // delayMicroseconds(1000000) // wait 1s (1000000 us)
  
  digitalWrite(13, LOW);
  
  delay(1000); // wait 1s (1000 ms)
  // delayMicroseconds(1000000) // wait 1s (1000000 us)
  
}
