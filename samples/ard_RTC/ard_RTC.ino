// Relogio com modulo RTC DS1307

// Include Variables

#include <DS1307.h>
 
// Init Variables

DS1307 rtc(A4, A5); // rtc(SDA,SCL)

// 
void setup()
{
  // Aciona o relogio
  rtc.halt(false);

  // Todo - função para setar hora com botão
  rtc.setDOW(TUESDAY);      //Define o dia da semana
  rtc.setTime(18, 20, 0);   //Define o horario
  rtc.setDate(3, 5, 2016);  //Define o dia, mes e ano

  // Definicoes do pino SQW/Out
  rtc.setSQWRate(SQW_RATE_1);
  rtc.enableSQW(true);

  Serial.begin(9600);
}
 
void loop()
{
  //Mostra as informações no Serial Monitor
  Serial.print("Hora : ");
  Serial.print(rtc.getTimeStr());
  Serial.print(" ");
  Serial.print("Data : ");
  Serial.print(rtc.getDateStr(FORMAT_SHORT));
  Serial.print(" ");
  Serial.println(rtc.getDOWStr(FORMAT_SHORT));
   
  //Aguarda 1 segundo e repete o processo
  delay (1000);
}
