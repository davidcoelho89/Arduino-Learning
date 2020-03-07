// Gerenal Example of LCD display

// Author: David Coelho
// Last Update: 2016-04-18

// Import Libraries

#include <LiquidCrystal.h>

// Define Pins

//LiquidCrystal lcd(<RS pin>, <enable pin>, <D4 pin>, <D5 pin>, <D6 pin>, <D7 pin>)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

// Init Variables

// Program Boot (Initialization)
void setup() 
{
  // Set digital pins' modes

  //Define number of colummns and lines of lcd
  lcd.begin(16,2);
}

// Main Loop (repeats indefinitely)
void loop() 
{
  //Clear LCD Screen
  lcd.clear();

  //Set cursor to columm 3,  and line 0;
  lcd.setCursor(3, 0);

  //Set LCD Text
  lcd.print("TESTE");

  //Set cursor to columm 3,  and line 1;
  lcd.setCursor(3, 1);

  //Set LCD Text
  lcd.print("LCD 16x2");

  //Wait 5s
  delay(5000);
  
  //Rolagem para a esquerda
  for (int pos = 0; pos < 3; pos++)
  {
    //Roll message to left
    lcd.scrollDisplayLeft();

    //Wait 0.3s
    delay(300);
  }
   
  //Rolagem para a direita
  for (int pos = 0; pos < 6; pos++)
  {
    //Roll message to right
    lcd.scrollDisplayRight();

    //Wait 0.3s
    delay(300);
  }

}
