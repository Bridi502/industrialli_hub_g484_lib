#include "digitalInputsPLC.h"

volatile bool industrialli_digitalInputs::_input_00 = false; // interrupt
volatile bool industrialli_digitalInputs::_input_01 = false;
volatile bool industrialli_digitalInputs::_input_02 = false;
volatile bool industrialli_digitalInputs::_input_03 = false;
volatile bool industrialli_digitalInputs::_input_04 = false;
volatile bool industrialli_digitalInputs::_input_05 = false;
volatile bool industrialli_digitalInputs::_input_06 = false;
volatile bool industrialli_digitalInputs::_input_07 = false;

void industrialli_digitalInputs::begin()
{

  beginInterruptInput_00();
  beginInterruptInput_01();
  beginInterruptInput_02();
  beginInterruptInput_03();
  beginInterruptInput_04();
  beginInterruptInput_05();
  beginInterruptInput_06();
  beginInterruptInput_07();

  readDigitalInputsStatus();
}
void industrialli_digitalInputs::readDigitalInputsStatus()
{
  if (digitalRead(PHOTO_00) == 1)
  {
    _input_00 = false;
  }
  else
  {
    _input_00 = true;
  }

  if (digitalRead(PHOTO_01) == 1)
  {
    _input_01 = false;
  }
  else
  {
    _input_01 = true;
  }

  if (digitalRead(PHOTO_02) == 1)
  {
    _input_02 = false;
  }
  else
  {
    _input_02 = true;
  }

  if (digitalRead(PHOTO_03) == 1)
  {
    _input_03 = false;
  }
  else
  {
    _input_03 = true;
  }

  if (digitalRead(PHOTO_04) == 1)
  {
    _input_04 = false;
  }
  else
  {
    _input_04 = true;
  }

  if (digitalRead(PHOTO_05) == 1)
  {
    _input_05 = false;
  }
  else
  {
    _input_05 = true;
  }

  if (digitalRead(PHOTO_06) == 1)
  {
    _input_06 = false;
  }
  else
  {
    _input_06 = true;
  }

  if (digitalRead(PHOTO_07) == 1)
  {
    _input_07 = false;
  }
  else
  {
    _input_07 = true;
  }
}

bool industrialli_digitalInputs::readDigitalInput(uint8_t pin)
{
  _pin = pin - 1;
  switch (_pin)
  {
  case 0:
    readDigitalInputsStatus();

    return _input_00;
    break;
  case 1:
    readDigitalInputsStatus();

    return _input_01;
    break;
  case 2:
    readDigitalInputsStatus();

    return _input_02;

    break;
  case 3:
    readDigitalInputsStatus();

    return _input_03;
    break;
  case 4:
    readDigitalInputsStatus();

    return _input_04;

    break;
  case 5:
    readDigitalInputsStatus();

    return _input_05;
    break;

  case 6:
    readDigitalInputsStatus();

    return _input_06;
    break;
  case 7:
    readDigitalInputsStatus();

    return _input_07;
    break;

  default:
    break;
  }
}
void industrialli_digitalInputs::updateDigitalInputsLeds()
{

  if (_input_00)
  {
    ledsPLC.ledOn(4);
  }
  else
  {
    ledsPLC.ledOff(4);
  }

  if (_input_01)
  {
    ledsPLC.ledOn(5);
  }
  else
  {
    ledsPLC.ledOff(5);
  }

  if (_input_02)
  {
    ledsPLC.ledOn(6);
  }
  else
  {
    ledsPLC.ledOff(6);
  }

  if (_input_03)
  {
    ledsPLC.ledOn(7);
  }
  else
  {
    ledsPLC.ledOff(7);
  }

  if (_input_04)
  {
    ledsPLC.ledOn(8);
  }
  else
  {
    ledsPLC.ledOff(8);
  }

  if (_input_05)
  {
    ledsPLC.ledOn(9);
  }
  else
  {
    ledsPLC.ledOff(9);
  }

  if (_input_06)
  {
    ledsPLC.ledOn(10);
  }
  else
  {
    ledsPLC.ledOff(10);
  }

  if (_input_07)
  {
    ledsPLC.ledOn(11);
  }
  else
  {
    ledsPLC.ledOff(11);
  }
}
