#include <stdint.h>
#include <avr/io.h>
#include "iButtonHw.hpp"
#include "iPinHw.hpp"
#include "buttonHw.hpp"

iButtonHw * iButtonHw::create(eButtonHwId buttonHwId, void(*callback)(void))
{
    iPinHw * hwPin = nullptr;

    switch (buttonHwId)
    {
    case eButtonHwId::pb1:
        hwPin = iPinHw::create(eHwPinId::PB1_LCD_DB4);
        break;
    case eButtonHwId::pb4:
        hwPin = iPinHw::create(eHwPinId::PB4_LCD_DB5);
        break;
    case eButtonHwId::pb5:
        hwPin = iPinHw::create(eHwPinId::PB5_LCD_DB6);
        break;
    default:
        break;
    }
    iButtonHw * buttonHw = new ButtonHw(hwPin, eButtonIntId::pcint0 ,&PCICR, &PCMSK0, callback);
    return buttonHw;
}