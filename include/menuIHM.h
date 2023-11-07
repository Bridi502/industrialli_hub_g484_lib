#ifndef MENUIHM_H
#define MENUIHM_H
extern bool relayOn;
extern int nextionPage;
#include <Nextion.h>
/*NEXTION*/
// pages
NexPage page0 = NexPage(0, 0, "page0");
NexPage page1 = NexPage(1, 0, "page1");
NexPage page2 = NexPage(2, 0, "page2");
NexPage page3 = NexPage(3, 0, "page3");
NexPage page4 = NexPage(4, 0, "page4");
NexPage page5 = NexPage(5, 0, "page5");

// page 00
NexButton m0_0 = NexButton(0, 2, "m0_0");

// page 01
NexButton driverEncoder = NexButton(1, 2, "driverEncoder");
NexButton sensors020 = NexButton(1, 3, "sensors020");
NexButton nodesLora = NexButton(1, 4, "nodesLora");
NexButton mod_exp = NexButton(1, 5, "mod_exp");
// page 02
NexButton startDriver = NexButton(2, 3, "startDriver");
NexButton stopDriver = NexButton(2, 4, "stopDriver");
NexButton menu = NexButton(2, 2, "menu");

// page 03
NexButton ativar = NexButton(3, 2, "ativar");
NexButton desativar = NexButton(3, 3, "desativar");
NexButton menu3 = NexButton(3, 4, "menu3");

// page 04
NexButton m0_4 = NexButton(4, 2, "m0_4");
NexNumber temp020 = NexNumber(4, 8, "temp020");
NexNumber press020 = NexNumber(4, 3, "press020");
NexProgressBar pgs_temp020 = NexProgressBar(4, 4, "pgs_temp020");
NexProgressBar pgs_press020 = NexProgressBar(4, 5, "pgs_press020");

// page 05

NexButton m0_5 = NexButton(5, 2, "m0_5");
NexNumber tempNode1 = NexNumber(5, 3, "tempNode1");
NexNumber umiNode1 = NexNumber(5, 6, "umiNode1");
NexProgressBar pgs_tempNode1 = NexProgressBar(5, 8, "pgs_tempNode1");
NexProgressBar pgs_humiNode1 = NexProgressBar(5, 11, "pgs_humiNode1");

NexTouch *nex_listen_list[] =
    {
        &driverEncoder,
        &sensors020,
        &nodesLora,
        &mod_exp,
        &startDriver,
        &stopDriver,
        &menu,
        &ativar,
        &desativar,
        &menu3,
        &m0_0,
        &m0_4,
        &m0_5,
        &page0,
        &page1,
        &page2,
        &page3,
        &page4,
        &page5,
        NULL};

// menu
void driverEncoderPushCallBack(void *ptr)
{
    page2.show();
    nextionPage = 2;
}
void sensors020PushCallBack(void *ptr)
{
    page4.show();
    nextionPage = 4;
}
void nodesLoraPushCallBack(void *ptr)
{
    page5.show();
    nextionPage = 5;
}

void modExpPushCallBack(void *ptr)
{
    page3.show();
    nextionPage = 3;
}

// Driver && Encoder
void startDriverPushCallBack(void *ptr)
{
        digitalOutputsPLC.writeDigitalOutput(6, LOW);
   
}
void stopDriverPushCallBack(void *ptr)
{
    digitalOutputsPLC.writeDigitalOutput(6, HIGH);
}
void menuPushCallBack(void *ptr)
{
    page1.show();
    nextionPage = 1;
}

//Modulo de expansao
void ativarPushCallBack(void *ptr)
{
    relayOn = true;
}
void desativarPushCallBack(void *ptr)
{
    relayOn = false;
}
void menu3PushCallBack(void *ptr)
{
    page1.show();
    nextionPage = 1;
}


void m0_0PushCallBack(void *ptr)
{
    page1.show();
    nextionPage = 1;
}

void m0_4PushCallBack(void *ptr)
{
    page1.show();
    nextionPage = 1;
}

void m0_5PushCallBack(void *ptr)
{
    page1.show();
    nextionPage = 1;
}



#endif
