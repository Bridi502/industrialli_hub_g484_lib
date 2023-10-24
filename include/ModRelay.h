#ifndef MODRELAY_H
#define MODRELAY_H
#include <Arduino.h>
#include "modulesPLC.h"

//invertido *corrigir no codigo do modulo*
#define MOD_K1 5
#define MOD_K2 4
#define MOD_K3 3
#define MOD_K4 2
#define MOD_K5 1
#define MOD_K6 0


void writeModRelay(int addrMod, int output, uint8_t value);
void testModRelay(int addrMod);
#endif