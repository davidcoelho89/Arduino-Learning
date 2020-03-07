// RTC DS1307 with LCD 16x2 sample

// Author: David Coelho
// Last Update: 2016-04-18

#include "Wire.h"
#include <LiquidCrystal.h>

// Init Variables

#define DS1307_ADDRESS 0x68
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
byte zero = 0x00; 

// Program Boot (Initialization)
void setup()
{
 // Define LCD's number of columms and lines
 lcd.begin(16,2);

 // Begin I2C communication
 Wire.begin();

 // Begin Serial communication
 Serial.begin(9600);

 // This can be commented if DS1307 is already set
 //SetDataAndTime(); 
}
 
void loop()
{
 showClock();
 delay(1000);
}

// Set Data and Time of DS1307 (just need to use it once per CI)
void SetDataAndTime()
{
 byte segs = 0;       // From 0 to 59
 byte mins = 25;      // From 0 to 59
 byte hrs = 19;       // From 0 to 23
 byte dayOfWeek = 2;  // From 0 to 06 (0 = Sunday)
 byte day = 3;        // From 1 to 31
 byte mes = 5;        // From 1 to 12
 byte ano = 16;       // From 0 to 99

 Wire.beginTransmission(DS1307_ADDRESS);
 
 // Stop CI so that it can receive data
 Wire.write(zero); 
 
 // Send data to DS1307
 Wire.write(ConverteParaBCD(segs));
 Wire.write(ConverteParaBCD(mins));
 Wire.write(ConverteParaBCD(hrs));
 Wire.write(ConverteParaBCD(dayOfWeek));
 Wire.write(ConverteParaBCD(day));
 Wire.write(ConverteParaBCD(mes));
 Wire.write(ConverteParaBCD(ano));
 Wire.write(zero); //Start no CI
 Wire.endTransmission(); 
}

// Auxiliary function 01
byte ConverteParaBCD(byte val)
{ 
 // Converte o número de decimal para BCD
 return ( (val/10*16) + (val%10) );
}

// Auxiliary function 02
byte ConverteparaDecimal(byte val) 
{ 
 // Converte de BCD para decimal
 return ( (val/16*10) + (val%16) );
}

// Get data from DS1307 and show it at LCD
void showClock()
{
 // Stop CI so that it can send data
 Wire.beginTransmission(DS1307_ADDRESS);
 Wire.write(zero);
 Wire.endTransmission();

 // Request bytes from DS1307
 Wire.requestFrom(DS1307_ADDRESS, 7);
 
 int segs = ConverteparaDecimal(Wire.read());
 int mins = ConverteparaDecimal(Wire.read());
 int hrs = ConverteparaDecimal(Wire.read() & 0b111111); 
 int dayOfWeek = ConverteparaDecimal(Wire.read()); 
 int day = ConverteparaDecimal(Wire.read());
 int mes = ConverteparaDecimal(Wire.read());
 int ano = ConverteparaDecimal(Wire.read());
  
 // Show current time at LCD
 lcd.setCursor(0, 0);
 if (hrs < 10)
   lcd.print("0");
 lcd.print(hrs);
 lcd.print(":");
 if (mins < 10)
   lcd.print("0");
 lcd.print(mins);
 lcd.print(":");
 if (segs < 10)
   lcd.print("0");
 lcd.print(segs);
  
 // Show current data at LCD
 lcd.setCursor(0, 1);
 lcd.print("Data : ");
 lcd.setCursor(7,1);
 if (day < 10)
   lcd.print("0");
 lcd.print(day);
 lcd.print(".");
 if (mes < 10)
   lcd.print("0");
 lcd.print(mes);
 lcd.print(".");
 lcd.print(ano);

 // Show day of Week at LCD
 lcd.setCursor(10,0);
 switch(dayOfWeek)
 {
  case 0:
    lcd.print("Dom");
    break;
  case 1:
    lcd.print("Seg");
    break;
  case 2:
    lcd.print("Ter");
    break;
  case 3:
    lcd.print("Qua");
    break;
  case 4:
    lcd.print("Qui");
    break;
  case 5:
    lcd.print("Sex");
    break;
  case 6:
    lcd.print("Sab");
    break;
 }

}
