#include "ModISO.h"
bool outputModIsoOnOff = true;
int digitalOutputModIso = 0;

void writeModISO(int addrMod, int output, uint8_t value){
  ModbusRTUClient.coilWrite(addrMod, output, value);
}
void readModISO(){
}
void testModISO(int addrMod){
      if (outputModIsoOnOff)
    {
      writeModISO(addrMod, digitalOutputModIso, HIGH);
    }
    else
    {
      writeModISO(addrMod, digitalOutputModIso, LOW);
    }

    if (digitalOutputModIso > 6)
    {
      digitalOutputModIso = -1;
      outputModIsoOnOff = !outputModIsoOnOff;
    }
    digitalOutputModIso++;
}