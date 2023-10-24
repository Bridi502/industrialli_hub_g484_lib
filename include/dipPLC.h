#ifndef DIPPLC_H
#define DIPPLC_H
#include <Arduino.h>

// DIP
#define DIP_01 PD4
#define DIP_02 PD5
#define DIP_03 PD6
#define DIP_04 PD7


class industrialli_dip{

public:
void begin();
bool readDIP(uint8_t dip);

private:
uint8_t _dip[4] = {
    DIP_01,
    DIP_02,
    DIP_03,
    DIP_04
};

};

#endif