#include <Arduino.h>
#include <startPLC.h>

industrialli_startPLC startPLC;

//timer para atualizacao dos leds
TIM_TypeDef *Instance = TIM2;
HardwareTimer *MyTim = new HardwareTimer(Instance);

// put function declarations here:
void ledsUpdate();

void setup()
{
  // put your setup code here, to run once:
  startPLC.begin();

  analogInputsPLC.setReadMode(ANLG_IN01, READ_020);

    //timer para atualizacao dos leds
  MyTim->setOverflow(120, HERTZ_FORMAT);
  MyTim->attachInterrupt(ledsUpdate);
  MyTim->resume();

}

void loop()
{
  // put your main code here, to run repeatedly:
   //digitalOutputsPLC.testOutputs();
  // digitalOutputsPLC.writeDigitalOutput(12, HIGH);
  bool input1 = digitalInputsPLC.readDigitalInput(0);
  digitalWrite(LED_DEBUG, input1);
}

// put function definitions here:
void ledsUpdate()
{
  digitalInputsPLC.updateDigitalInputsLeds();
  ledsPLC.ledsUpdate();
}