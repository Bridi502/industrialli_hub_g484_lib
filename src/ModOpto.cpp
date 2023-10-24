#include "ModOpto.h"

uint8_t modOpto[8] = {
    modOpto[0] = 0,
    modOpto[1] = 0,
    modOpto[2] = 0,
    modOpto[3] = 0,
    modOpto[4] = 0,
    modOpto[5] = 0,
    modOpto[6] = 0,
    modOpto[7] = 0};

void requestFromModOpto(int addrMod){
 ModbusRTUClient.requestFrom(addrMod, COILS, 0, 8);
  while (ModbusRTUClient.available())
  {
    modOpto[0] = ModbusRTUClient.read();
    modOpto[1] = ModbusRTUClient.read();
    modOpto[2] = ModbusRTUClient.read();
    modOpto[3] = ModbusRTUClient.read();
    modOpto[4] = ModbusRTUClient.read();
    modOpto[5] = ModbusRTUClient.read();
    modOpto[6] = ModbusRTUClient.read();
    modOpto[7] = ModbusRTUClient.read();
}
}
uint8_t readModOpto(int input)
{
    return modOpto[input];
  
}