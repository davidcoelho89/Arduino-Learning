// Serial Write Example

// Author: David Coelho
// Last Update: 2016-04-18

// Import Libraries

// Dont need libraries for this example

// Init Variables

char inByte;       // holds byte received from the serial port
int nBytesBuffer;  // holds the number of bytes at serial buffer

// Define Pins

int ledPin = 13; // Onboard LED (D13)
int potPin = 0;  // Potentiometer (A0)
int bt1 = 4;     // button 1 (D4)
int bt2 = 5;     // button 2 (D5)

// Program Boot (Initialization)
void setup()
{
  // Set digital pins' modes
  pinMode(ledPin, OUTPUT);
  pinMode(bt1, INPUT_PULLUP);
  pinMode(bt2, INPUT_PULLUP);

  // Turn led On
  digitalWrite(ledPin,HIGH);
  
  // Init Serial Communication
  Serial.begin(9600, SERIAL_8N1);
}

// Main Loop (repeats indefinitely)
void loop()
{
  // Send button 1 status
  if (digitalRead(bt1))
    Serial.write('d');
  else
    Serial.write('l');
    
  // Wait 1s for next sending
  delay(1000);

  // Send button 2 status
  if (digitalRead(bt2))
    Serial.write('D');
  else
    Serial.write('L');
    
  // Wait 1s for next sending
  delay(1000);

  // Send potentiometer Value
  if(analogRead(potPin) > 512)
    Serial.print('M');
  else
    Serial.print('m');

  // Wait 1s for next sending
  delay(1000);

}

