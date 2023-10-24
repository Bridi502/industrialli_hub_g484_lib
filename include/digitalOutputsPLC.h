#ifndef DIGITALOUTPUTSPLC_H
#define DIGITALOUTPUTSPLC_H
#include <Arduino.h>
#include "ledsPLC.h"
extern Industrialli_ledsCTRL ledsPLC;
// Output dig.

#define IC1_ISO_DIS PE11
#define IC2_ISO_DIS PF2

#define IC1_ISO_DIAG PE7
#define IC2_ISO_DIAG PC3

#define ISO_CS PE10
#define ISO_SCK PE9
#define ISO_SI PE8


class industrialli_digitalOutputs
{

public:
    void begin();
    void writeDigitalOutput(uint8_t Q, bool output);
    void testOutputs();
    void ledOutput(uint8_t led, uint8_t onOff);
    

private:

uint8_t _Q[16] = {0};
uint8_t _qNum;
uint8_t _buffer = 0;
uint8_t _led;
bool _onOff = false;
    bool outputOnOff = true;
    int digitalOutput = 0;
};
#endif