#ifndef ANALOGINPUTSPLC_H
#define ANALOGINPUTSPLC_H

#include <Arduino.h>
#include <stdlib.h>
#include <ledsPLC.h>

extern Industrialli_ledsCTRL ledsPLC;

// Input anlg.
#define VIN_01 PD10
#define VIN_02 PD11
#define VIN_03 PD12
#define VIN_04 PD13
// Relay sel.
#define _RELAY_SEL_01 PD0
#define _RELAY_SEL_02 PD1
#define _RELAY_SEL_03 PD2
#define _RELAY_SEL_04 PD3

#define ANLG_IN01 0
#define ANLG_IN02 1
#define ANLG_IN03 2
#define ANLG_IN04 3

class industrialli_analogInputs
{
public:
    void begin(void);
    void setReadMode(uint8_t anlgPin, uint8_t readMode);
    int readRawInput(uint8_t anlgPin);
    int getVRefRaw(void);
    double getVIN(uint8_t anlgPin);
    double get010V(uint8_t anlgPin);
    double get020mA(uint8_t anlgPin);
    void setLedClass(Industrialli_ledsCTRL &ledClass);
    bool alarm020mA(uint8_t anlgPin, float threshold);
    int getIntParamVREF(void);
    int getIntParamTSCAL1(void);
    int getIntParamTSCAL2(void);

private:
    uint8_t _anlgPin;
    uint8_t _pin;
    uint8_t _readMode;

#define READ_010 0
#define READ_020 1

    int _VREFINT;
    int _TS_CAL1;
    int _TS_CAL2;
    int _VREF_RAW = 0;
    int _VIN_RAW[4] = {0};
    int _bitsADC = 4095;
    double _VREF_INTERNAL = 1.212;
    double _VDDA = 0.00;
    double _VIN[4] = {0.00};
    double _VIN010[4] = {0.00};
    double _AIN020[4] = {0.00};

    bool _alarm = false;
};

#endif