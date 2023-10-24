#ifndef LEDSPLC_H
#define LEDSPLC_H

#include <Arduino.h>
#include <stdlib.h>

//Shift Register
#define _SR_SER PB2
#define _SR_RCLK PB0
#define _SR_SRCLK PB1





class Industrialli_ledsCTRL{
    public:

void begin(void);
void start(void);
void ledsOff(void);
void ledOn(uint8_t _ledNum);
void ledOff(uint8_t _ledNum);
void ledsUpdate(void);

    private:
    
uint8_t _led[32] = {0};
uint8_t _buffer = 0;

uint8_t _leds4[8] = {_led[7], _led[6], _led[5], _led[4], _led[3], _led[2], _led[1], _led[0]};
uint8_t _leds3[8] = {_led[15], _led[14], _led[13], _led[12], _led[11], _led[10], _led[9], _led[8]};
uint8_t _leds2[8] = {_led[23], _led[22], _led[21], _led[20], _led[19], _led[18], _led[17], _led[16]};
uint8_t _leds1[8] = {_led[31], _led[30], _led[29], _led[28], _led[27], _led[26], _led[25], _led[24]};

uint8_t _ledNum;
};

#endif