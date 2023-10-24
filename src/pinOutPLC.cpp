#include "pinOutPLC.h"
void pinModePLC(){
  pinMode(PGOOD1, INPUT);
  pinMode(PGOOD2, INPUT);
  pinMode(LED_DEBUG, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  
 

  pinMode(SDCARD_CS, OUTPUT);
  pinMode(SDCARD_DETECT, INPUT);

  pinMode(EEPROM_WP, OUTPUT);

 
 
  //pinMode(W5500_CS, OUTPUT);
  //pinMode(W5500_RST, OUTPUT);
  //pinMode(W5500_INT, INPUT);

  
  pinMode(RS485_UART4_RE_DE, OUTPUT);
  pinMode(RS485_TER_SEL, OUTPUT);
  pinMode(RS485_MOD_RE_DE, OUTPUT);

  digitalWrite(LED_DEBUG, HIGH);

  digitalWrite(SDCARD_CS, HIGH);

  //digitalWrite(EEPROM_WP, HIGH);



  //digitalWrite(W5500_CS, HIGH);
  //digitalWrite(W5500_RST, LOW);
  digitalWrite(LED_DEBUG, LOW);
  
}