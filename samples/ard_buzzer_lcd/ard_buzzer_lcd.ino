// Buzzer + LCD + Button

// Author: David Coelho
// Last Update: 2016-04-18

// Import Libraries

#include <LiquidCrystal.h>

// Define Pins

//LiquidCrystal lcd(<RS pin>, <enable pin>, <D4 pin>, <D5 pin>, <D6 pin>, <D7 pin>)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int BUZ_pin = 9;
int led_Pin = 13;
int bot_pin = 8;

// Init Variables

int tempo = 10;
int current_freq = 0;

int escala1[] = { 65, 69, 73, 78, 82, 87, 93, 98, 104, 110, 117, 124};
int escala2[] = { 131, 139, 147, 156, 165, 175, 185, 196, 208, 220, 233, 247};
int escala3[] = { 262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};
int escala4[] = { 524, 554, 587, 622, 659, 698, 740, 784, 830, 880, 932, 989};
int escala5[] = { 1047, 1108, 1174, 1244, 1318, 1397, 1480, 1568, 1661, 1760, 1864, 1975};

#define c3  262
#define cs3 277
#define d3  294
#define ds3 311
#define e3  330
#define f3  349
#define fs3 370
#define g3  392
#define gs3 415
#define a3  440
#define as3 466
#define b3  494

#define c4  524
#define cs4 554
#define d4  587
#define ds4 622
#define e4  659
#define f4  698
#define fs4 740
#define g4  784
#define gs4 830
#define a4  880
#define as4 932
#define b4  987

void setup() 
{
  // Set digital pins' modes
  pinMode(led_Pin, OUTPUT);
  pinMode(BUZ_pin, OUTPUT);
  pinMode(bot_pin, INPUT_PULLUP);

  //Define number of colummns and lines of lcd
  lcd.begin(16,2);
}

void loop() 
{
  //Clear LCD Screen
  lcd.clear();

  //Set cursor to columm 1, and line 0;
  lcd.setCursor(1, 0);

  //Set LCD Text
  lcd.print("DAVID E NICE");

  //Set cursor to columm 1, and line 1;
  lcd.setCursor(2, 1);

  //Set LCD Text
  lcd.print("13-06-2008");

  //Wait until button is pressed
  while(digitalRead(bot_pin));

  //Play music
  music_one();

  //Wait 1s
  delay(1000);
}

void beep (unsigned char buzzer_pin, int frequencyInHertz, long timeInMilliseconds)
{
    //use led to visualize the notes being played
    digitalWrite(led_Pin, HIGH);
 
    int x;
    long delayAmount = (long)(1000000/frequencyInHertz);
    long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
    for (x=0;x<loopTime;x++)
    {
        digitalWrite(buzzer_pin,HIGH);
        delayMicroseconds(delayAmount);
        digitalWrite(buzzer_pin,LOW);
        delayMicroseconds(delayAmount);
    }
 
    //set led back to low
    digitalWrite(led_Pin, LOW);
 
    //a little delay to make all notes sound separate
    delay(20);
}

void first_part()
{
  beep(BUZ_pin, e4, 250);
  beep(BUZ_pin, e4, 250);
  beep(BUZ_pin, e4, 250);
  beep(BUZ_pin, g4, 250);
  beep(BUZ_pin, e4, 250);
  beep(BUZ_pin, d4, 250);
  beep(BUZ_pin, c4, 2000);

  beep(BUZ_pin, a3, 250);
  beep(BUZ_pin, c4, 250);
  beep(BUZ_pin, a3, 250);
  beep(BUZ_pin, c4, 250);
  beep(BUZ_pin, a3, 500);
  beep(BUZ_pin, c4, 250);
  beep(BUZ_pin, c4, 250);
  beep(BUZ_pin, b3, 2000);
}

void second_part()
{
  beep(BUZ_pin, c4, 250);
  beep(BUZ_pin, c4, 250);
  beep(BUZ_pin, a3, 250);
  beep(BUZ_pin, c4, 500);
  beep(BUZ_pin, a3, 250);
  beep(BUZ_pin, c4, 250);
  beep(BUZ_pin, ds4, 250);
  beep(BUZ_pin, d4, 250);
  beep(BUZ_pin, c4, 250);
  beep(BUZ_pin, d4, 1000);  
}

void music_one()
{
  first_part();
  first_part();

  second_part();

  beep(BUZ_pin, c4, 250);
  beep(BUZ_pin, d4, 250);
  beep(BUZ_pin, c4, 250);
  beep(BUZ_pin, e4, 250);
  beep(BUZ_pin, e4, 1000);

  beep(BUZ_pin, g4, 250);
  beep(BUZ_pin, d4, 350);
  beep(BUZ_pin, c4, 2000);

  second_part();

  beep(BUZ_pin, c4, 250);
  beep(BUZ_pin, d4, 250);
  beep(BUZ_pin, e4, 250);
  beep(BUZ_pin, d4, 250);
  beep(BUZ_pin, e4, 250);
  beep(BUZ_pin, b3, 500);
  beep(BUZ_pin, a3, 250);
  beep(BUZ_pin, g3, 250);
  beep(BUZ_pin, b3, 250);
  beep(BUZ_pin, a3, 2000);

  second_part();

  beep(BUZ_pin, d4, 500);
  beep(BUZ_pin, c4, 2000);
  
}

