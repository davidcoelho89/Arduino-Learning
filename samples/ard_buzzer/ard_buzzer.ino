// Play  musical notes with internal library

// Author: David Coelho
// Last Update: 16-04-18

// Init Variables

int tempo = 10;
int current_freq = 0;

// The next semitone is the previous one times 2^(1/12)
// The previous semitone is the next one divided by 2^(1/12)
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

// Define Pins
int buz_pin = 9;
int led_Pin = 13;

// Program Boot (Initialization)
void setup() 
{
  // Set digital pins' modes
  pinMode(led_Pin, OUTPUT);
  pinMode(buz_pin, OUTPUT);
}

// Main Loop (repeats indefinitely)
void loop()
{
  //third_scale();
  //cristal_buzzer();
  //do_re_mi_fa();
  //siren_sound();
  //imperial_march();
}

// Play all the notes from third scale
void third_scale()
{
  for (int i = 0; i < 12; i++) 
  {
    tone(buz_pin, escala3[i], 1000);
    delay(1000);
  }
  delay(1000);
}

// Play sound for buzzer with internal cristal
void cristal_buzzer()
{
  digitalWrite(buz_pin,HIGH);
  delay(500);
  digitalWrite(buz_pin,LOW);
  delay(500);
}

// Play siren sound
void siren_sound()
{
  for (current_freq = 150; current_freq < 1800; current_freq += 1) 
  {
    tone(buz_pin, current_freq, tempo); 
    delay(1);
  }
  for (current_freq = 1800; current_freq > 150; current_freq -= 1) 
  {
    tone(buz_pin, current_freq, tempo); 
    delay(1);
  }
}

// Play do-re-mi-fa sound
void do_re_mi_fa()
{
    delay(2000);
    tone(buz_pin,262,200); //DO
    delay(200);
    tone(buz_pin,294,300); //RE
    delay(200);
    tone(buz_pin,330,300); //MI
    delay(200);
    tone(buz_pin,349,300); //FA
    delay(300);
    tone(buz_pin,349,300); //FA
    delay(300);
    tone(buz_pin,349,300); //FA
    delay(300);
    tone(buz_pin,262,100); //DO
    delay(200);
    tone(buz_pin,294,300); //RE
    delay(200);   
    tone(buz_pin,262,100); //DO
    delay(200);
    tone(buz_pin,294,300); //RE
    delay(300);
    tone(buz_pin,294,300); //RE
    delay(300);
    tone(buz_pin,294,300); //RE
    delay(300);
    tone(buz_pin,262,200); //DO
    delay(200);
    tone(buz_pin,392,200); //SOL
    delay(200);
    tone(buz_pin,349,200); //FA
    delay(200);
    tone(buz_pin,330,300); //MI
    delay(300);
    tone(buz_pin,330,300); //MI
    delay(300);
    tone(buz_pin,330,300); //MI
    delay(300);
    tone(buz_pin,262,200); //DO
    delay(200);
    tone(buz_pin,294,300); //RE
    delay(200);
    tone(buz_pin,330,300); //MI
    delay(200);
    tone(buz_pin,349,300); //FA
    delay(300);
    tone(buz_pin,349,300); //FA
    delay(300);
    tone(buz_pin,349,300); //FA
    delay(300);
}

// Auxiliary Function for imperial march
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

// Play imperial march sound
void imperial_march()
{
    //for the sheet music see:
    //http://www.musicnotes.com/sheetmusic/mtd.asp?ppn=MN0016254
    //this is just a translation of said sheet music to frequencies / time in ms
    //used 500 ms for a quart note
 
    beep(buz_pin, a3, 500);
    beep(buz_pin, a3, 500);
    beep(buz_pin, a3, 500);
    beep(buz_pin, f3, 350);
    beep(buz_pin, c4, 150);
 
    beep(buz_pin, a3, 500);
    beep(buz_pin, f3, 350);
    beep(buz_pin, c4, 150);
    beep(buz_pin, a3, 1000);
 
    beep(buz_pin, e4, 500);
    beep(buz_pin, e4, 500);
    beep(buz_pin, e4, 500);
    beep(buz_pin, f4, 350);
    beep(buz_pin, c4, 150);
 
    beep(buz_pin, gs3, 500);
    beep(buz_pin, f3, 350);
    beep(buz_pin, c4, 150);
    beep(buz_pin, a3, 1000);
 
    beep(buz_pin, a4, 500);
    beep(buz_pin, a3, 350);
    beep(buz_pin, a3, 150);
    beep(buz_pin, a4, 500);
    beep(buz_pin, gs4, 250);
    beep(buz_pin, g4, 250);
 
    beep(buz_pin, fs4, 125);
    beep(buz_pin, f4, 125);
    beep(buz_pin, fs4, 250);
    
    delay(250);
    
    beep(buz_pin, as3, 250);
    beep(buz_pin, ds4, 500);
    beep(buz_pin, d4, 250);
    beep(buz_pin, cs4, 250);
 
    beep(buz_pin, c4, 125);
    beep(buz_pin, b3, 125);
    beep(buz_pin, c4, 250);
    
    delay(250);
    
    beep(buz_pin, f3, 125);
    beep(buz_pin, gs3, 500);
    beep(buz_pin, f3, 375);
    beep(buz_pin, a3, 125);
 
    beep(buz_pin, c4, 500);
    beep(buz_pin, a3, 375);
    beep(buz_pin, c4, 125);
    beep(buz_pin, e4, 1000);
 
    beep(buz_pin, a4, 500);
    beep(buz_pin, a3, 350);
    beep(buz_pin, a3, 150);
    beep(buz_pin, a4, 500);
    beep(buz_pin, gs4, 250);
    beep(buz_pin, g4, 250);
 
    beep(buz_pin, fs4, 125);
    beep(buz_pin, f4, 125);
    beep(buz_pin, fs4, 250);
    
    delay(250);
    
    beep(buz_pin, as3, 250);
    beep(buz_pin, ds4, 500);
    beep(buz_pin, d4, 250);
    beep(buz_pin, cs4, 250);
 
    beep(buz_pin, c4, 125);
    beep(buz_pin, b3, 125);
    beep(buz_pin, c4, 250);

    delay(250);
   
    beep(buz_pin, f3, 250);
    beep(buz_pin, gs3, 500);
    beep(buz_pin, f3, 375);
    beep(buz_pin, c4, 125);
 
    beep(buz_pin, a3, 500);
    beep(buz_pin, f3, 375);
    beep(buz_pin, c3, 125);
    beep(buz_pin, a3, 1000);
}

