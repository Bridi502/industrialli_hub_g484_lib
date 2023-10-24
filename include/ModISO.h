#ifndef MODISO_H
#define MODISO_H
#include <Arduino.h>
#include "modulesPLC.h"

#define MOD_Q1 0
#define MOD_Q2 1
#define MOD_Q3 2
#define MOD_Q4 3
#define MOD_Q5 4
#define MOD_Q6 5
#define MOD_Q7 6
#define MOD_Q8 7
#define MOD_DIS 8




void writeModISO(int addrMod, int output, uint8_t value);
void readModISO();
void testModISO(int addrMod);

#endif