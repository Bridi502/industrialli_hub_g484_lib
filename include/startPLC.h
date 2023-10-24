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
// #include <Nextion.h>
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



class industrialli_startPLC
{
private:
    /* data */
public:
    void begin();
};

void industrialli_startPLC::begin()
{
    pinModePLC();
    analogInputsPLC.begin();
    digitalInputsPLC.begin();
    digitalOutputsPLC.begin();
    // dipPLC.begin();
    ledsPLC.begin();

    SerialUSB.begin(115200);
    Serial1.begin(9600);   // NEXTION
    Serial2.begin(115200); // MOD. EXP.
    Serial3.begin(9600);   // LORA
    Serial4.begin(9600);   // RS485
}

#endif