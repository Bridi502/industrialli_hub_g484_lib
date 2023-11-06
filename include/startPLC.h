#ifndef STARTPLC_H
#define STARTPLC_H
#include <stdlib.h>
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <HardwareSerial.h>
#include <ArduinoRS485.h>
#include <ArduinoModbus.h>
#include <HardwareSerial.h>
#include "ledsPLC.h"
#include "analogInputsPLC.h"
#include "AddrModbusIndustrialli.h"
#include "pinOutPLC.h"
#include "digitalInputsPLC.h"
#include "digitalOutputsPLC.h"
#include "dipPLC.h"
#include "ModISO.h"
#include "ModRelay.h"
#include "ModOpto.h"
#include "ModMAX.h"
#include <SoftwareSerial.h>
#include <SD.h>
#include <Nextion.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include <Ethernet2.h>
#include <EthernetClient.h>
#include <Dns.h>
#include <Dhcp.h>

HardwareSerial Serial1(NEXTION_RXD1, NEXTION_TXD1);
HardwareSerial Serial2(RS485_MOD_RXD2, RS485_MOD_TXD2);
HardwareSerial Serial3(LORA_USART3_RX, LORA_USART3_TX);
HardwareSerial Serial4(RS485_UART4_RX, RS485_UART4_TX);

Industrialli_ledsCTRL ledsPLC;
industrialli_analogInputs analogInputsPLC;
industrialli_digitalInputs digitalInputsPLC;
industrialli_digitalOutputs digitalOutputsPLC;
industrialli_dip dipPLC;

bool step = 0;
int steps = 0;
int sendNextionMessage = 0;
bool sendMsgNextion = false;
int counterPos;
int counterNeg;
extern int addrModRelay;
extern int addrModOpto;
extern int addrModIso;
extern bool relayOn;

// timer para atualizacao dos leds
TIM_TypeDef *Instance = TIM2;
HardwareTimer *MyTim = new HardwareTimer(Instance);

TIM_TypeDef *Instance3 = TIM3;
HardwareTimer *MyTim3 = new HardwareTimer(Instance3);

TIM_TypeDef *Instance4 = TIM4;
HardwareTimer *MyTim4 = new HardwareTimer(Instance4);

class industrialli_startPLC
{
private:
    /* data */
public:
    void begin();
    static void ledsUpdate()
    {
        noInterrupts();
        digitalInputsPLC.updateDigitalInputsLeds();
        digitalOutputsPLC.isoDiag();
        ledsPLC.ledsUpdate();
        interrupts();
    }
    static void driverSteps()
    {
        noInterrupts();

        if (rotation == true && counter != 0)
        {
            // CW
            if (counter < 0)
            {
                counter++;
            }
            else
            {
                counter--;
            }
            step = !step;
            digitalOutputsPLC.writeDigitalOutput(8, step);
            digitalOutputsPLC.writeDigitalOutput(7, LOW);
        }
        else if (rotation == false && counter != 0)
        {
            // CCW
            if (counter < 0)
            {
                counter++;
            }
            else
            {
                counter--;
            }
            step = !step;
            digitalOutputsPLC.writeDigitalOutput(8, step);
            digitalOutputsPLC.writeDigitalOutput(7, HIGH);
        }
        interrupts();
    }
    static void comms()
    {

        // SerialUSB.println(counter);
//writeModISO(addrModIso, MOD_DIS, HIGH);
        requestFromModOpto(addrModOpto);
        if(readModOpto(MOD_IN1)){
            writeModISO(addrModIso, MOD_Q8, HIGH);
        }
        else{
            writeModISO(addrModIso, MOD_Q8, LOW);
        }

        if (relayOn)
        {
            writeModRelay(addrModRelay, MOD_K3, HIGH);
        }
        else
        {
            writeModRelay(addrModRelay, MOD_K3, LOW);
        }

        sendNextionMessage++;
        if (sendNextionMessage == 500)
        {
            sendMsgNextion = true;
            sendNextionMessage = 0;
        }
    }
};

void industrialli_startPLC::begin()
{
    /************************* Industrialli *************************/
    pinModePLC();
    analogInputsPLC.begin();
    digitalInputsPLC.begin();
    digitalOutputsPLC.begin();
    // dipPLC.begin();
    ledsPLC.begin();

    /************************* Serial *************************/
    SerialUSB.begin(115200);
    Serial1.begin(9600); // NEXTION
                         // Serial1.print("baud=9600");
    // Serial1.write(0xff);
    // Serial1.write(0xff);
    //  Serial1.write(0xff);
    // Serial1.end();
    //  Serial1.begin(115200);

    Serial2.begin(115200); // MOD. EXP.
    Serial3.begin(9600);   // LORA
    Serial4.begin(9600);   // RS485

    /************************* Arduino RS485 *************************/

    // RS485Class RS485(Serial4, RS485_MOD_TXD2, RS485_MOD_RE_DE, LED_DEBUG); //Serial port, TX, DE, RE
    //  teve conflito com o SerialUSB habilitado, foi necessario modificar RS485.cpp
    RS485.setPins(RS485_MOD_TXD2, RS485_MOD_RE_DE, -1);
    // RS485.setPins(RS485_UART4_TX, RS485_UART4_RE_DE, -1);
    RS485.begin(115200);
    // RS485.setDelays(0, 10);

    /************************* Arduino Modbus *************************/

    ModbusRTUClient.begin(115200);
    ModbusRTUClient.setTimeout(10);
    /************************* Timers *************************/
    MyTim->setOverflow(120, HERTZ_FORMAT);
    MyTim->attachInterrupt(ledsUpdate);
    MyTim->resume();

    MyTim3->setOverflow(1000, MICROSEC_FORMAT);
    MyTim3->attachInterrupt(driverSteps);
    MyTim3->resume();

    // MyTim4->setOverflow(100, MICROSEC_FORMAT);
    MyTim4->setOverflow(200, HERTZ_FORMAT);
    MyTim4->attachInterrupt(comms);
    MyTim4->resume();
}

#endif