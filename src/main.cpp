#include <Arduino.h>
#include <startPLC.h>

industrialli_startPLC startPLC;

// put function declarations here:

void setup()
{
  // put your setup code here, to run once:
  startPLC.begin();                                 // inicializa os perifericos do CLP
  analogInputsPLC.setReadMode(ANLG_IN01, READ_020); // seta a entrada A01 para leitura de sensores de 0-20mA
  analogInputsPLC.setReadMode(ANLG_IN02, READ_010); // seta a entrada A02 para leitura de sensores de 0-10V
}

void loop()
{
  // put your main code here, to run repeatedly:

  // digitalOutputsPLC.writeDigitalOutput(12, HIGH); //escreve a saida Q12 em HIGH
  // digitalOutputsPLC.writeDigitalOutput(8, LOW); //escreve a saida Q8 em LOW
  // analogInputsPLC.get020mA(ANLG_IN01); //le a entrada A01 (0-20mA);
  // analogInputsPLC.get010V(ANLG_IN02); //le a entrada A02 (0-10V);
  // digitalInputsPLC.readDigitalInput(2); //le a entrada I02
  // digitalInputsPLC.readDigitalInput(6); //le a entrada I06

  digitalOutputsPLC.testOutputs();
  SerialUSB.println("Hello world!");
  bool input1 = digitalInputsPLC.readDigitalInput(1);
  digitalWrite(LED_DEBUG, input1);
}

// put function definitions here:
