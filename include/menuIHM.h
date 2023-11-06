#ifndef MENUIHM_H
#define MENUIHM_H
extern bool relayOn;
#include <Nextion.h>
/*NEXTION*/
// pages
NexPage page0 = NexPage(0, 0, "page0");
NexPage page1 = NexPage(1, 0, "page1");
NexPage page2 = NexPage(2, 0, "page2");
NexPage page3 = NexPage(3, 0, "page3");
NexPage page4 = NexPage(4, 0, "page4");
NexPage page5 = NexPage(5, 0, "page5");
NexPage page6 = NexPage(6, 0, "page6");

// page 00
NexButton m0_0 = NexButton(0, 2, "m0_0");

// page 01
NexButton driverEncoder = NexButton(1, 2, "driverEncoder");
NexButton sensors020 = NexButton(1, 3, "sensors020");
NexButton nodesLora = NexButton(1, 4, "nodesLora");

// page 02
NexButton startDriver = NexButton(2, 3, "startDriver");
NexButton stopDriver = NexButton(2, 4, "stopDriver");
NexButton menu = NexButton(2, 2, "menu");

// page 03
NexButton voltar = NexButton(3, 5, "voltar");
NexNumber rpm = NexNumber(3, 2, "rpm");
NexNumber pulsos = NexNumber(3, 3, "pulsos");
NexText direcao = NexText(3, 4, "direcao");

// page 04
NexButton m0_4 = NexButton(4, 12, "m0_4");
NexNumber temp020 = NexNumber(4, 8, "temp020");
NexNumber press020 = NexNumber(4, 3, "press020");
NexProgressBar pgs_temp020 = NexProgressBar(4, 4, "pgs_temp020");
NexProgressBar pgs_press020 = NexProgressBar(4, 5, "pgs_press020");

// page 05

NexButton m0_5 = NexButton(5, 12, "m0_5");
NexButton m1_5 = NexButton(5, 13, "m1_5");
NexNumber tempNode1 = NexNumber(5, 3, "tempNode1");
NexNumber umiNode1 = NexNumber(5, 6, "umiNode1");
NexProgressBar pgs_tempNode1 = NexProgressBar(5, 8, "pgs_tempNode1");
NexProgressBar pgs_humiNode1 = NexProgressBar(5, 11, "pgs_humiNode1");

// page 06
NexButton m0_6 = NexButton(6, 12, "m0_6");
NexNumber tempNode2 = NexNumber(6, 4, "tempNode2");
NexNumber umiNode2 = NexNumber(6, 5, "umiNode2");
NexProgressBar pgs_tempNode2 = NexProgressBar(6, 8, "pgs_tempNode2");
NexProgressBar pgs_humiNode2 = NexProgressBar(6, 7, "pgs_humiNode2");



NexTouch *nex_listen_list[] =
    {
      &driverEncoder,
     &sensors020,
    &nodesLora,
       &startDriver,
       &stopDriver,
       &menu,
       &voltar,
        //&rpm,
        &pulsos,
        //&direcao,
        //&temp020,
        //&press020,

        //&tempNode1,
        //&umiNode1,
        &m0_0,
        &m0_4,
        &m0_5,
        &m1_5,
        &m0_6,
        //&tempNode2,
        //  &umiNode2,
        &page0,
        &page1,
        &page2,
        &page3,
        &page4,
        &page5,
        &page6,
        NULL};


//menu
void driverEncoderPushCallBack(void *ptr)
{
    page2.show();
}
void sensors020PushCallBack(void *ptr)
{
    page4.show();
}
void nodesLoraPushCallBack(void *ptr)
{
    page5.show();
}

//Driver && Encoder
void startDriverPushCallBack(void *ptr)
{
    page3.show();
    digitalOutputsPLC.writeDigitalOutput(6, LOW);
    relayOn = true;
   
}
void stopDriverPushCallBack(void *ptr)
{
    digitalOutputsPLC.writeDigitalOutput(6, HIGH);
    relayOn = false;
    
}
void menuPushCallBack(void *ptr)
{
    page1.show();
}
void voltarPushCallBack(void *ptr)
{
    page2.show();
}





void m0_0PushCallBack(void *ptr)
{
    page1.show();
}

void m0_4PushCallBack(void *ptr)
{
    page1.show();
}



void m0_5PushCallBack(void *ptr)
{
    page1.show();
}

void m1_5PushCallBack(void *ptr)
{
    page6.show();
}
void m0_6PushCallBack(void *ptr)
{
    page5.show();
}

#endif
