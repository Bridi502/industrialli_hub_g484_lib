#include "digitalOutputsPLC.h"

void industrialli_digitalOutputs::begin()
{
}

void industrialli_digitalOutputs::ledOutput(uint8_t led, uint8_t onOff)
{
    /*
    Q1 -> LED12
    Q2 -> LED13
    Q3 -> LED14
    Q4 -> LED15
    Q5 -> LED16
    Q6 -> LED17
    Q7 -> LED18
    Q8 -> LED19
    */

    _led = led;
    _onOff = onOff;
    switch (_led)
    {
    case 0: // Q1
        if (_onOff)
        {
            ledsPLC.ledOn(12);
        }
        else
        {
            ledsPLC.ledOff(12);
        }
        break;

    case 1: // Q2
        if (_onOff)
        {
            ledsPLC.ledOn(13);
        }
        else
        {
            ledsPLC.ledOff(13);
        }
        break;

    case 2: // Q3
        if (_onOff)
        {
            ledsPLC.ledOn(14);
        }
        else
        {
            ledsPLC.ledOff(14);
        }
        break;

    case 3: // Q4
        if (_onOff)
        {
            ledsPLC.ledOn(15);
        }
        else
        {
            ledsPLC.ledOff(15);
        }
        break;

    case 4: // Q5
        if (_onOff)
        {
            ledsPLC.ledOn(16);
        }
        else
        {
            ledsPLC.ledOff(16);
        }
        break;

    case 5: // Q6
        if (_onOff)
        {
            ledsPLC.ledOn(17);
        }
        else
        {
            ledsPLC.ledOff(17);
        }
        break;

    case 6: // Q7
        if (_onOff)
        {
            ledsPLC.ledOn(18);
        }
        else
        {
            ledsPLC.ledOff(18);
        }
        break;

    case 7: // Q8
        if (_onOff)
        {
            ledsPLC.ledOn(19);
        }
        else
        {
            ledsPLC.ledOff(19);
        }
        break;
        /*
            Q9 -> LED24
            Q10 -> LED25
            Q11 -> LED26
            Q12 -> LED27
            Q13 -> LED28
            Q14 -> LED29
            Q15 -> LED30
            Q16 -> LED31

        */

    case 8: // Q9
        if (_onOff)
        {
            ledsPLC.ledOn(24);
        }
        else
        {
            ledsPLC.ledOff(24);
        }
        break;

    case 9: // Q10
        if (_onOff)
        {
            ledsPLC.ledOn(25);
        }
        else
        {
            ledsPLC.ledOff(25);
        }
        break;

    case 10: // Q11
        if (_onOff)
        {
            ledsPLC.ledOn(27);
        }
        else
        {
            ledsPLC.ledOff(27);
        }
        break;

    case 11: // Q12
        if (_onOff)
        {
            ledsPLC.ledOn(26);
        }
        else
        {
            ledsPLC.ledOff(26);
        }
        break;

    case 12: // Q13
        if (_onOff)
        {
            ledsPLC.ledOn(28);
        }
        else
        {
            ledsPLC.ledOff(28);
        }
        break;

    case 13: // Q14
        if (_onOff)
        {
            ledsPLC.ledOn(29);
        }
        else
        {
            ledsPLC.ledOff(29);
        }
        break;

    case 14: // Q15
        if (_onOff)
        {
            ledsPLC.ledOn(30);
        }
        else
        {
            ledsPLC.ledOff(30);
        }
        break;

    case 15: // Q16
        if (_onOff)
        {
            ledsPLC.ledOn(31);
        }
        else
        {
            ledsPLC.ledOff(31);
        }
        break;

    default:
        break;
    }
    //ledsPLC.ledsUpdate();
}

void industrialli_digitalOutputs::writeDigitalOutput(uint8_t qNum, bool output)
{
    if (output)
    {
        _qNum = qNum - 1;
        _Q[_qNum] = 1;
    }
    else
    {
        _qNum = qNum - 1;
        _Q[_qNum] = 0;
    }
    uint8_t _output1[8] = {_Q[7], _Q[6], _Q[5], _Q[4], _Q[3], _Q[2], _Q[1], _Q[0]};
    uint8_t _output2[8] = {_Q[15], _Q[14], _Q[13], _Q[12], _Q[11], _Q[10], _Q[9], _Q[8]};

    digitalWrite(ISO_CS, LOW);

    _buffer += (_output2[0] << 7); // Q9
    _buffer += (_output2[1] << 6);
    _buffer += (_output2[2] << 5);
    _buffer += (_output2[3] << 4);
    _buffer += (_output2[4] << 3);
    _buffer += (_output2[5] << 2);
    _buffer += (_output2[6] << 1);
    _buffer += (_output2[7] << 0); // Q16
    shiftOut(ISO_SI, ISO_SCK, MSBFIRST, _buffer);
    _buffer = 0;

    _buffer += (_output1[0] << 7); // Q1
    _buffer += (_output1[1] << 6);
    _buffer += (_output1[2] << 5);
    _buffer += (_output1[3] << 4);
    _buffer += (_output1[4] << 3);
    _buffer += (_output1[5] << 2);
    _buffer += (_output1[6] << 1);
    _buffer += (_output1[7] << 0); // Q8
    shiftOut(ISO_SI, ISO_SCK, MSBFIRST, _buffer);
    _buffer = 0;

    digitalWrite(ISO_CS, HIGH);
    ledOutput(_qNum, output);
}

void industrialli_digitalOutputs::testOutputs()
{
    for(int i = 0; i < 17; i++){
        writeDigitalOutput(i, HIGH);
        delay(100);
    }
    for(int i = 16; i > 0; i --){
        writeDigitalOutput(i, LOW);
        delay(100);
    }
}
