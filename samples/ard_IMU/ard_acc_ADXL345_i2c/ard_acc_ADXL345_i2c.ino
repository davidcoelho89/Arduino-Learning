// Include Libraries
#include <Wire.h>

#define DEVICE 0x53   //ADXL345 device address
#define nBytes 6      //Number of bytes to read each time (two bytes for each axis)

byte buff[nBytes];    //6 bytes buffer for saving data read from the device
char str[512];        //string to print

int DataReg = 0x32;   //first acc mesure data register on the ADXL345
int FormReg = 0x31;   //format of reading value
int PowerReg = 0x2D;  //Power control register

int x, y, z;          //hold data from each axis

void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
  
  //Turning on the ADXL345
  writeTo(DEVICE, PowerReg, 0);      
  writeTo(DEVICE, PowerReg, 16);
  writeTo(DEVICE, PowerReg, 8);

  //Set data reading for +-4g
  writeTo(DEVICE, FormReg, 1);
}

void loop()
{
  //read the acceleration data from the ADXL345
  readFrom(DEVICE, DataReg, nBytes, buff);

 //Axis reading -> 10 bit (2 bytes).  LSB first.
 //Converting both bytes into one int
  x = (((int)buff[1]) << 8) | buff[0];   
  y = (((int)buff[3])<< 8) | buff[2];
  z = (((int)buff[5]) << 8) | buff[4];

  // Offsets
  x = x - 28;
  y = y + 162;
  z = z - 438;
  
  //Send the x y z values as a string to the serial port
  sprintf(str, "%d %d %d", x, y, z);  
  Serial.print(str);
  Serial.write(10);
  
  //Delay is needed in order not to clog the port
  delay(100);
}

void writeTo(int device, byte address, byte val) 
{
   Wire.beginTransmission(device);  //start transmission to device 
   Wire.write(address);             // send register address
   Wire.write(val);                 // send value to write
   Wire.endTransmission();          //end transmission
}

void readFrom(int device, byte address, int num, byte buff[]) 
{
  Wire.beginTransmission(device); //start transmission to device 
  Wire.write(address);            //sends address to read from
  Wire.endTransmission();         //end transmission
  
  Wire.beginTransmission(device); //start transmission to device (initiate again)
  Wire.requestFrom(device, num);  // request 6 bytes from device
  
  int i = 0;
  while(Wire.available())         //device may send less than requested (abnormal)
  { 
    buff[i] = Wire.read();        // receive a byte
    i++;
  }
  Wire.endTransmission();         //end transmission
}
