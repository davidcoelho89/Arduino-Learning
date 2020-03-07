// Arduino I2C Sample (scanner of devices)

// Author: David Coelho
// Last Update: 2016-04-18

// Libraries

#include <Wire.h>

// Variables

byte error;
byte address;
int nDevices;

// Program Boot (Initialization)
void setup() 
{
  Wire.begin();

  Serial.begin(9600,SERIAL_8N1);
  while (!Serial); // For Arduino Leonardo: wait for serial monitor
  Serial.println("\nI2C Scanner");
}

// Main Loop (repeats indefinitely)
void loop() 
{
  Serial.println("Scanning...");

  nDevices = 0;
  for(address = 1; address < 127; address++ ) 
  {
    Wire.beginTransmission(address);
    
    // see if a device did acknowledge to the address
    error = Wire.endTransmission();

    // Found a device
    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.println(address,HEX);

      nDevices++;
    }

    // Didnt recognize error
    else if (error==4) 
    {
      Serial.print("Unknow error at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.println(address,HEX);
    }
  }
  
  // Finish scanning
  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("done\n");

  // wait 2s for next scan
  delay(5000);
}
