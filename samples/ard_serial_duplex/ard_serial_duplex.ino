// Serial Read / Write Example

// Author: David Coelho
// Last Update: 2016-04-18

// Import Libraries

// Dont need libraries for this example

// Init Variables

int sensorValue = 0;   // current sensor value
int bt1Value = 0;      // current button value
char serialValue = 0;  // Character received through serial

int nBytesBuffer = 0;  // Number of available bytes in buffer

char START_BYTE = '*'; // Character used for Serial communication
char DELIMITER = ',';  // Character used for Serial communication
char END_BYTE = '#';   // Character used for Serial communication

// Define Pins

int sensorPin = 0;     // Potenciometer (A0)
int bt1Pin = 2;        // BUTTON (D2)
int ledPin = 13;       // Onboard LED (D13)

// Function to wait until something is sent from serial
void establishContact() 
{
  while (Serial.available() <= 0)
  {
    Serial.println("Ola");
    delay(1000);
  }
}

// Program Boot (Initialization)
void setup()
{
  // Set digital pins' modes
  pinMode(bt1Pin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);   

  // Init Serial Communication
  Serial.begin(9600, SERIAL_8N1);

  // Wait until an outside read value happens
  establishContact();
}

// Main Loop (repeats indefinitely)
void loop()
{
  // Assign Values
  sensorValue = analogRead(sensorPin);
  bt1Value = digitalRead(bt1Pin);

  // Send bytes for serial (last byte is an empty string with a '\n' value at the end)
  Serial.write(START_BYTE);
  Serial.print(DELIMITER);
  Serial.print(sensorValue);
  Serial.print(DELIMITER);
  Serial.print(bt1Value);
  Serial.print(DELIMITER);
  Serial.write(END_BYTE);
  Serial.println();

  // println() differs from print() and write() by adding a '\n' at the end
  // write() and print() have small difference. see references.

  // Wait 50ms
  delay(50);
}

void serialEvent()
{
  // Get number of available bytes at buffer (max = 64)
  nBytesBuffer = Serial.available();
  
  // Check if there are any bytes in buffer
  if(nBytesBuffer > 0)
  {
    // read first buffer's byte
    serialValue = Serial.read();

    switch(serialValue)
    {
      case '1':
        digitalWrite(ledPin,HIGH);
        break;
      case '2':
        digitalWrite(ledPin,LOW);
        break;
    }
  }
  
}

