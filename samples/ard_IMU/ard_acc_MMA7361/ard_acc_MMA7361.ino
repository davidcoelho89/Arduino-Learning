// Get data from Acelerometer

// Author: David Coelho
// Last Update: 2016-04-18

// Import Library
#include <AcceleroMMA7361.h>

// Init Variables
AcceleroMMA7361 accelero;
int XaxisValue = 0;
int YaxisValue = 0;
int ZaxisValue = 0;

// Program Boot (Initialization)
void setup()
{
  // Set Accelerometer variables
  accelero.begin(13, 12, 11, 10, A0, A1, A2);
  accelero.setARefVoltage(3.3); //sets the AREF voltage to 3.3V
  accelero.setSensitivity(LOW); //sets the sensitivity to +/-6G
  accelero.calibrate(); // set the axis' offset
                        // z must be perpendicular to g

  // Init Serial Communication
  Serial.begin(9600,SERIAL_8N1);
}

// Main Loop (repeats indefinitely)
void loop()
{
  // Assign Values
  XaxisValue = accelero.getXAccel();
  YaxisValue = accelero.getYAccel();
  ZaxisValue = accelero.getZAccel();

  // Send String
  Serial.print("\nx: ");
  Serial.print(XaxisValue);
  Serial.print(" \ty: ");
  Serial.print(YaxisValue);
  Serial.print(" \tz: ");
  Serial.print(ZaxisValue);
  Serial.print("\tG*10^-2");

  // Wait 1s
  delay(1000);
}
