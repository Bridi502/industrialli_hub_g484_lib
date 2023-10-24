#include "ModRelay.h"
bool outputModRelayOnOff = true;
int outputModRelay = 0;

void writeModRelay(int addrMod, int output, uint8_t value)
{
    ModbusRTUClient.coilWrite(addrMod, output, value);
}

void testModRelay(int addrMod){
      if (outputModRelayOnOff)
    {
      writeModRelay(addrMod, outputModRelay, HIGH);
    }
    else
    {
      writeModRelay(addrMod, outputModRelay, LOW);
    }

    if (outputModRelay > 4)
    {
      outputModRelay = -1;
      outputModRelayOnOff = !outputModRelayOnOff;
    }
    outputModRelay++;
}