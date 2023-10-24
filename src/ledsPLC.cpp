#include "ledsPLC.h"

void Industrialli_ledsCTRL::begin(void)
{
  

  pinMode(_SR_SER, OUTPUT);
  pinMode(_SR_RCLK, OUTPUT);
  pinMode(_SR_SRCLK, OUTPUT);
  start();
  ledsOff();
}

void Industrialli_ledsCTRL::ledsOff(void)
{
  for (int i = 0; i > 32; i++)
  {
    _led[i] = 0;
  }
  ledsUpdate();
}

void Industrialli_ledsCTRL::ledOn(uint8_t ledNum)
{
  _ledNum = ledNum;
  _led[_ledNum] = 1;
}

void Industrialli_ledsCTRL::ledOff(uint8_t ledNum)
{
  _ledNum = ledNum;
  _led[_ledNum] = 0;
}
void Industrialli_ledsCTRL::start(void)
{
  for (int i = 0; i < 32; i++)
  {
    ledOn(i);
    ledOff(i - 1);
    ledsUpdate();
    delay(10);
  }
  for (int i = 32; i >= -1; i--)
  {
    ledOn(i);
    ledOff(i + 1);
    ledsUpdate();
    delay(10);
  }
}

void Industrialli_ledsCTRL::ledsUpdate(void)
{

  uint8_t _leds4[8] = {_led[7], _led[6], _led[5], _led[4], _led[3], _led[2], _led[1], _led[0]};
  uint8_t _leds3[8] = {_led[15], _led[14], _led[13], _led[12], _led[11], _led[10], _led[9], _led[8]};
  uint8_t _leds2[8] = {_led[23], _led[22], _led[21], _led[20], _led[19], _led[18], _led[17], _led[16]};
  uint8_t _leds1[8] = {_led[31], _led[30], _led[29], _led[28], _led[27], _led[26], _led[25], _led[24]};

  digitalWrite(_SR_RCLK, LOW);
  _buffer += (_leds1[0] << 7);
  _buffer += (_leds1[1] << 6);
  _buffer += (_leds1[2] << 5);
  _buffer += (_leds1[3] << 4);
  _buffer += (_leds1[4] << 3);
  _buffer += (_leds1[5] << 2);
  _buffer += (_leds1[6] << 1);
  _buffer += (_leds1[7] << 0);
  shiftOut(_SR_SER, _SR_SRCLK, LSBFIRST, _buffer);
  _buffer = 0;

  digitalWrite(_SR_RCLK, LOW);
  _buffer += (_leds2[0] << 7);
  _buffer += (_leds2[1] << 6);
  _buffer += (_leds2[2] << 5);
  _buffer += (_leds2[3] << 4);
  _buffer += (_leds2[4] << 3);
  _buffer += (_leds2[5] << 2);
  _buffer += (_leds2[6] << 1);
  _buffer += (_leds2[7] << 0);
  shiftOut(_SR_SER, _SR_SRCLK, LSBFIRST, _buffer);
  _buffer = 0;

  _buffer += (_leds3[0] << 7);
  _buffer += (_leds3[1] << 6);
  _buffer += (_leds3[2] << 5);
  _buffer += (_leds3[3] << 4);
  _buffer += (_leds3[4] << 3);
  _buffer += (_leds3[5] << 2);
  _buffer += (_leds3[6] << 1);
  _buffer += (_leds3[7] << 0);
  shiftOut(_SR_SER, _SR_SRCLK, LSBFIRST, _buffer);
  _buffer = 0;

  _buffer += (_leds4[0] << 7);
  _buffer += (_leds4[1] << 6);
  _buffer += (_leds4[2] << 5);
  _buffer += (_leds4[3] << 4);
  _buffer += (_leds4[4] << 3);
  _buffer += (_leds4[5] << 2);
  _buffer += (_leds4[6] << 1);
  _buffer += (_leds4[7] << 0);
  shiftOut(_SR_SER, _SR_SRCLK, LSBFIRST, _buffer);
  digitalWrite(_SR_RCLK, HIGH);
  _buffer = 0;
}
