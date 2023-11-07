#include <Arduino.h>
#include <startPLC.h>
#include "menuIHM.h"

int addrModOpto = 2;
int addrModIso = 3;
int addrModRelay = 1;

int aState;
int aLastState;
int counter;
int stepperDir;
bool rotation;
int nextionPage = 0;

bool relayOn = false;

float pressureSensor010Bar;

float tempSensor0150C;
int valPgs_press020;
int valPgs_temp020;
float nodeTemp1Raw;
float nodeHumi1Raw;
float nodeTemp1;
float nodeHumi1;
int pgs_nodeTemp1;
int pgs_nodeHumi1;

industrialli_startPLC startPLC;

byte mac[] = {
    0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02};

// put function declarations here:

void setup()
{
  // put your setup code here, to run once:
  startPLC.begin(); // inicializa os perifericos do CLP
  // NEXTION
  nexInit();
  driverEncoder.attachPush(driverEncoderPushCallBack, &driverEncoder);
  sensors020.attachPush(sensors020PushCallBack, &sensors020);
  nodesLora.attachPush(nodesLoraPushCallBack, &nodesLora);
  mod_exp.attachPush(modExpPushCallBack, &mod_exp);
   ativar.attachPush(ativarPushCallBack, &ativar);
    desativar.attachPush(desativarPushCallBack, &desativar);
  startDriver.attachPush(startDriverPushCallBack, &startDriver);
  stopDriver.attachPush(stopDriverPushCallBack, &stopDriver);

  menu.attachPush(menuPushCallBack, &menu);
  menu3.attachPush(menuPushCallBack, &menu3);
  m0_0.attachPush(m0_0PushCallBack, &m0_0);
  m0_4.attachPush(m0_4PushCallBack, &m0_4);
  m0_5.attachPush(m0_5PushCallBack, &m0_5);
 

  digitalWrite(IC1_ISO_DIS, HIGH);
  digitalWrite(IC2_ISO_DIS, HIGH);
  aLastState = digitalInputsPLC.readDigitalInput(1);

  analogInputsPLC.setReadMode(ANLG_IN01, READ_020); // seta a entrada A01 para leitura de sensores de 0-20mA
  analogInputsPLC.setReadMode(ANLG_IN02, READ_020); // seta a entrada A02 para leitura de sensores de 0-10V

  /*
    SPI.setMISO(SPI1_MISO);
    SPI.setMOSI(SPI1_MOSI);
    SPI.setSCLK(SPI1_SCK);
    SPI.begin();
    Ethernet.init(SPI1_W5500_CS);

      // Open SerialUSB communications and wait for port to open:
    SerialUSB.begin(115200);
    // this check is only needed on the Leonardo:
    while (!SerialUSB) {
      ; // wait for SerialUSB port to connect. Needed for Leonardo only
    }

    // start the Ethernet connection:
    if (Ethernet.begin(mac) == 0) {
      SerialUSB.println("Failed to configure Ethernet using DHCP");
      // no point in carrying on, so do nothing forevermore:
      for (;;)
        ;
    }
    // print your local IP address:
    SerialUSB.print("My IP address: ");
    for (byte thisByte = 0; thisByte < 4; thisByte++) {
      // print the value of each byte of the IP address:
      SerialUSB.print(Ethernet.localIP()[thisByte], DEC);
      SerialUSB.print(".");
    }
    SerialUSB.println();

  */
}

void loop()
{
  nexLoop(nex_listen_list);
  if (sendMsgNextion == true)
  {
    switch (nextionPage)
    {
    case 4:
      temp020.setValue(tempSensor0150C);
      press020.setValue(pressureSensor010Bar);
      pgs_temp020.setValue(valPgs_temp020);
      pgs_press020.setValue(valPgs_press020);
      break;

    case 5:
      tempNode1.setValue(nodeTemp1);
      umiNode1.setValue(nodeHumi1);
      pgs_tempNode1.setValue(pgs_nodeTemp1);
      pgs_humiNode1.setValue(pgs_nodeHumi1);
      break;

    default:
      break;
    }
    sendMsgNextion = false;
  }
  //

  // put your main code here, to run repeatedly:

  // digitalOutputsPLC.writeDigitalOutput(12, HIGH); //escreve a saida Q12 em HIGH
  // digitalOutputsPLC.writeDigitalOutput(8, LOW); //escreve a saida Q8 em LOW
  // analogInputsPLC.get020mA(ANLG_IN01); //le a entrada A01 (0-20mA);
  // analogInputsPLC.get010V(ANLG_IN02); //le a entrada A02 (0-10V);
  // digitalInputsPLC.readDigitalInput(2); //le a entrada I02
  // digitalInputsPLC.readDigitalInput(6); //le a entrada I06

  // digitalOutputsPLC.testOutputs();
  // SerialUSB.println("Hello world!");
  // bool input1 = digitalInputsPLC.readDigitalInput(1);
  // digitalWrite(LED_DEBUG, input1);
  float pressureSensor020Raw = analogInputsPLC.get020mA(ANLG_IN01);
  pressureSensor010Bar = (((pressureSensor020Raw - 3.80) * 10.00 / (20.00 - 3.80)) + 1.00) * 100;
  float tempSensor020Raw = analogInputsPLC.get020mA(ANLG_IN02);
  tempSensor0150C = (((tempSensor020Raw - 4.00) / (20.00 - 4.00)) * (200.00 - 0.00) + 0.00) * 100;

  valPgs_press020 = map(pressureSensor020Raw, 0.00, 20.00, 0, 100);
  valPgs_temp020 = map(tempSensor020Raw, 0.00, 20.00, 0, 100);

  if (sendNow)
  {
    lora.write_node_function(1, 3);
    nodeTemp1Raw = lora.read_NodeTemp();
    nodeTemp1 = nodeTemp1Raw * 100;
    pgs_nodeTemp1 = map(nodeTemp1Raw, 0.00, 100.00, 0, 100);
  }
  else
  {

    lora.write_node_function(1, 4);
    nodeHumi1Raw = lora.read_NodeHumi();
    nodeHumi1 = nodeHumi1Raw * 100;
    pgs_nodeHumi1 = map(nodeHumi1Raw, 0.00, 100.00, 0, 100);
  }

  /*
          float val020 = nodeVal / 1000.00;
        // float loraFloat = float(lora.read_applicationCommand());
        SerialUSB.println(val020);

        pressureProgBar = map(val020, 0.00, 20.00, 0, 100);
        // sensorPressureVal = map(val020, 0.00, 20.00, 0.00, 10.00)* 100;
        sensorPressureVal = (((val020 - 3.80) * 10.00 / (20.00 - 3.80)) + 1.00) * 100;
        pressure020.setValue(sensorPressureVal);
        pressure020Pgs.setValue(pressureProgBar);



  */
}

// put function definitions here:
