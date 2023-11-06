#ifndef DIGITALINPUTSPLC_H
#define DIGITALINPUTSPLC_H
#include <Arduino.h>
#include "ledsPLC.h"
extern Industrialli_ledsCTRL ledsPLC;
extern int aState;
extern int counter;
extern bool rotation;

// Input dig.
#define PHOTO_00 PD14
#define PHOTO_01 PD15 
#define PHOTO_02 PB4
#define PHOTO_03 PB5
#define PHOTO_04 PB6 
#define PHOTO_05 PB9
#define PHOTO_06 PE0 
#define PHOTO_07 PE1 

class industrialli_digitalInputs
{
public:
    static volatile bool _input_00; // interrupt
    static volatile bool _input_01;
    static volatile bool _input_02;
    static volatile bool _input_03;
    static volatile bool _input_04;
    static volatile bool _input_05;

    static volatile bool _input_06;
    static volatile bool _input_07;

    static void beginInterruptInput_00() // interrupt
    {
        pinMode(PHOTO_00, INPUT);
        attachInterrupt(digitalPinToInterrupt(PHOTO_00), interruptInput_00, CHANGE);
    }
    static void interruptInput_00(void)
    {
        noInterrupts();
        _input_00 = !_input_00;

        //encoder
        aState = _input_00;
        if( _input_01 != aState){
            counter++;
            rotation = true;

        }
        else{
            counter--;
            rotation = false;
        }
        interrupts();
    }

    static void beginInterruptInput_01() // interrupt
    {
        pinMode(PHOTO_01, INPUT);
        attachInterrupt(digitalPinToInterrupt(PHOTO_01), interruptInput_01, CHANGE);
    }
    static void interruptInput_01(void)
    {
        noInterrupts();
        _input_01 = !_input_01;
        interrupts();
    }

    static void beginInterruptInput_02() // interrupt
    {
        pinMode(PHOTO_02, INPUT);
        attachInterrupt(digitalPinToInterrupt(PHOTO_02), interruptInput_02, CHANGE);
    }
    static void interruptInput_02(void)
    {
        noInterrupts();
        _input_02 = !_input_02;
        interrupts();
    }

    static void beginInterruptInput_03() // interrupt
    {
        pinMode(PHOTO_03, INPUT);
        attachInterrupt(digitalPinToInterrupt(PHOTO_03), interruptInput_03, CHANGE);
    }
    static void interruptInput_03(void)
    {
        noInterrupts();
        _input_03 = !_input_03;
        interrupts();
    }

    static void beginInterruptInput_04() // interrupt
    {
        pinMode(PHOTO_04, INPUT);
        attachInterrupt(digitalPinToInterrupt(PHOTO_04), interruptInput_04, CHANGE);
    }
    static void interruptInput_04(void)
    {
        noInterrupts();
        _input_04 = !_input_04;
        interrupts();
    }

    static void beginInterruptInput_05() // interrupt
    {
        pinMode(PHOTO_05, INPUT);
        attachInterrupt(digitalPinToInterrupt(PHOTO_05), interruptInput_05, CHANGE);
    }
    static void interruptInput_05(void)
    {
        noInterrupts();
        _input_05 = !_input_05;
        interrupts();
    }

    static void beginInterruptInput_06() // interrupt
    {
        pinMode(PHOTO_06, INPUT);
        attachInterrupt(digitalPinToInterrupt(PHOTO_06), interruptInput_06, CHANGE);
    }
    static void interruptInput_06(void)
    {
        noInterrupts();
        _input_06 = !_input_06;
        interrupts();
    }

    static void beginInterruptInput_07() // interrupt
    {
        pinMode(PHOTO_07, INPUT);
        attachInterrupt(digitalPinToInterrupt(PHOTO_07), interruptInput_07, CHANGE);
    }
    static void interruptInput_07(void)
    {
        noInterrupts();
        _input_07 = !_input_07;
        interrupts();
    }

    void begin();
    bool readDigitalInput(uint8_t pin);
    void updateDigitalInputsLeds();

private:
    void readDigitalInputsStatus();
    int _pin;
};

#endif