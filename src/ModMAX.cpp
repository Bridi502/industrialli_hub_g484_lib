#include <modulesPLC.h>

int tempModMAX[4] ={
  tempModMAX[0] = 0,
  tempModMAX[1] = 0,
  tempModMAX[2] = 0,
  tempModMAX[3] = 0
};
void requestFromModMAX(int addrMod){
  ModbusRTUClient.requestFrom(addrMod, HOLDING_REGISTERS, 0, 4);
   while (ModbusRTUClient.available())
  {
  tempModMAX[0] = ModbusRTUClient.read();
  tempModMAX[1] = ModbusRTUClient.read();
  tempModMAX[2] = ModbusRTUClient.read();
  tempModMAX[3] = ModbusRTUClient.read();
  }
}

int readMAX(int input){
    return tempModMAX[input];
}