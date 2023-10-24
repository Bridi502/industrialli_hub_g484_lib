#ifndef MODOPTO_H
#define MODOPTO_H
#include <Arduino.h>
#include "modulesPLC.h"

#define MOD_IN1 0
#define MOD_IN2 1
#define MOD_IN3 2
#define MOD_IN4 3
#define MOD_IN5 4
#define MOD_IN6 5
#define MOD_IN7 6
#define MOD_IN8 7

void requestFromModOpto(int addrMod);
uint8_t readModOpto(int input);


#endif