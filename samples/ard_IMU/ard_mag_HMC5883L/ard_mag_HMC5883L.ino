// Arduino Magnetometer HMC5883L Sample

// Author: David Coelho
// Last Update: 2016-04-18

// Libraries

#include <Wire.h>

// Variables

#define address 0x1E

// Program Boot (Initialization)
void setup() 
{
  Wire.begin();

  Serial.begin(9600,SERIAL_8N1);
  while (!Serial); // For Arduino Leonardo: wait for serial monitor
  Serial.println("Inicializing L3G4200D");

  // Inicializa o HMC5883
  Wire.beginTransmission(address);
  // Seleciona o modo
  Wire.write(0x02); 
  // Modo de medicao continuo
  Wire.write(0x00); 
  Wire.endTransmission();
}

// Main Loop (repeats indefinitely)
void loop() 
{
int x,y,z; //triple axis data
  
  // Indica ao HMC5883 para iniciar a leitura
  Wire.beginTransmission(address);
  Wire.write(0x03); //select register 3, X MSB register
  Wire.endTransmission();
 
  // Le os dados de cada eixo, 2 registradores por eixo
  Wire.requestFrom(address, 6);
  if(6<=Wire.available())
  {
    x = Wire.read()<<8; //X msb
    x |= Wire.read(); //X lsb
    z = Wire.read()<<8; //Z msb
    z |= Wire.read(); //Z lsb
    y = Wire.read()<<8; //Y msb
    y |= Wire.read(); //Y lsb
  }
  
  // Imprime os vaores no serial monitor
  Serial.print("x: ");
  Serial.print(x);
  Serial.print("  y: ");
  Serial.print(y);
  Serial.print("  z: ");
  Serial.println(z);
  
  delay(250);
}
