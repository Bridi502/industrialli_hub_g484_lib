#include "analogInputsPLC.h"

void industrialli_analogInputs::begin(void)
{ // inicia as entradas analogicas e seta para a leitura de 0-10V

    pinMode(VIN_01, INPUT);
    pinMode(VIN_02, INPUT);
    pinMode(VIN_03, INPUT);
    pinMode(VIN_04, INPUT);

    pinMode(_RELAY_SEL_01, OUTPUT);
    pinMode(_RELAY_SEL_02, OUTPUT);
    pinMode(_RELAY_SEL_03, OUTPUT);
    pinMode(_RELAY_SEL_04, OUTPUT);
    // LOW - 0-10V
    // HIGH - 0-20mA
    digitalWrite(_RELAY_SEL_01, LOW);
    digitalWrite(_RELAY_SEL_02, LOW);
    digitalWrite(_RELAY_SEL_03, LOW);
    digitalWrite(_RELAY_SEL_04, LOW);

    analogReadResolution(12);
    getIntParamVREF();
}
void industrialli_analogInputs::setReadMode(uint8_t anlgPin, uint8_t readMode)
{ // escolhe o tipo de leitura
    // 1 - 0-20mA
    // 0 - 0-10V

    _anlgPin = anlgPin;
    _readMode = readMode;

    if (_anlgPin == 0)
    {
        if (_readMode == 1)
        {
            digitalWrite(_RELAY_SEL_01, HIGH);
            ledsPLC.ledOn(0);
            //ledsPLC.ledsUpdate();

        }
        else
        {
            digitalWrite(_RELAY_SEL_01, LOW);
            ledsPLC.ledOff(0);
            //ledsPLC.ledsUpdate();
        }
    }

    else if (_anlgPin == 1)
    {
        if (_readMode == 1)
        {
            digitalWrite(_RELAY_SEL_02, HIGH);
            ledsPLC.ledOn(1);
            //ledsPLC.ledsUpdate();
        }
        else
        {
            digitalWrite(_RELAY_SEL_02, LOW);
            ledsPLC.ledOff(1);
            //ledsPLC.ledsUpdate();
        }
    }

    else if (_anlgPin == 2)
    {
        if (_readMode == 1)
        {
            digitalWrite(_RELAY_SEL_03, HIGH);
            ledsPLC.ledOn(2);
            //ledsPLC.ledsUpdate();
        }
        else
        {
            digitalWrite(_RELAY_SEL_03, LOW);
            ledsPLC.ledOff(2);
            //ledsPLC.ledsUpdate();
        }
    }
    else if (_anlgPin == 3)
    {
        if (_readMode == 1)
        {
            digitalWrite(_RELAY_SEL_04, HIGH);
            ledsPLC.ledOn(3);
            //ledsPLC.ledsUpdate();
        }
        else
        {
            digitalWrite(_RELAY_SEL_04, LOW);
            ledsPLC.ledOff(3);
            //ledsPLC.ledsUpdate();
        }
    }
}
int industrialli_analogInputs::readRawInput(uint8_t anlgPin)
{ // seta a leitura para 0-10V e retorna o valor da entrada

    _anlgPin = anlgPin;
    // analogReadResolution(12);

    if (_anlgPin == 0)
    {
        _VIN_RAW[0] = analogRead(VIN_01);
        _pin = 0;
    }

    else if (_anlgPin == 1)
    {
        _VIN_RAW[1] = analogRead(VIN_02);
        _pin = 1;
    }

    else if (_anlgPin == 2)
    {
        _VIN_RAW[2] = analogRead(VIN_03);
        _pin = 2;
    }
    else if (_anlgPin == 3)
    {
        _VIN_RAW[3] = analogRead(VIN_04);
        _pin = 3;
    }

    return _VIN_RAW[_pin];
}
int industrialli_analogInputs::getVRefRaw(void)
{
    // obtem o valor da leitura da tensao de referencia interna
    _VREF_RAW = analogRead(AVREF);
    return _VREF_RAW;
}
double industrialli_analogInputs::getVIN(uint8_t anlgPin)
{
    // obtem a tensao de saida na entrada selecionada
    _anlgPin = anlgPin;
    _VDDA = (_VREF_INTERNAL * _bitsADC) / getVRefRaw();
    _VIN[_anlgPin] = _VDDA / _bitsADC * readRawInput(_anlgPin);
    return _VIN[_anlgPin];
}
double industrialli_analogInputs::get010V(uint8_t anlgPin)
{
    // obtem a tensao de 0-10V na entrada selecionada

    _anlgPin = anlgPin;
    _VDDA = (_VREF_INTERNAL * _bitsADC) / getVRefRaw();
    //_VIN010[_anlgPin] = getVIN(_anlgPin) * (10.00 / 3.30);
    _VIN010[_anlgPin] = getVIN(_anlgPin) * (10.00 / _VDDA);
    return _VIN010[_anlgPin];
}
double industrialli_analogInputs::get020mA(uint8_t anlgPin)
{
    // obtem  a corrente de 0-20mA na entrada selecionada
    _anlgPin = anlgPin;
    _VDDA = (_VREF_INTERNAL * _bitsADC) / getVRefRaw();
    _AIN020[_anlgPin] = getVIN(_anlgPin) * (20.00 / _VDDA);
    //_AIN020[_anlgPin] = getVIN(_anlgPin) * (20.00 /3.30);
    return _AIN020[_anlgPin];
}
bool industrialli_analogInputs::alarm020mA(uint8_t anlgPin, float threshold)
{
    // alerta de falha para leitura 0-20mA
    _anlgPin = anlgPin;
    if (get020mA(_anlgPin) < threshold)
    {
        ledsPLC.ledOn(31);
        _alarm = true;
    }
    else
    {
        ledsPLC.ledOff(31);
        _alarm = false;
    }
    return _alarm;
}
int industrialli_analogInputs::getIntParamVREF(void){
    _VREFINT = *((unsigned short *) 0x1FFF75AA);
    _VREF_INTERNAL = _VREFINT;
    
    return _VREFINT;
}
int industrialli_analogInputs::getIntParamTSCAL1(void){
    
    _TS_CAL1 = *((unsigned short *) 0x1FFF75A8);
   
    return _TS_CAL1;
}
int industrialli_analogInputs::getIntParamTSCAL2(void){
    
    _TS_CAL2 = *((unsigned short *) 0x1FFF75CA);
    return _TS_CAL2;
}