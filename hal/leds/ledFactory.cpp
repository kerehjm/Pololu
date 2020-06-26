/* 
* LedFactory.cpp
*
* Created: 17/05/2020 11:08:01
* Author: Mathew.Kuloba
*/


#include "ledFactory.h"

iLed *LedFactory::create(eLedId ledId)
{
    iLed *led = nullptr;
    switch(ledId)
    {
        case eLedId::green:
        led = new Led(PinFactory::create(ePinId::PD7_GREEN_LED));
        break;
        case eLedId::red:
        led = new Led(PinFactory::create(ePinId::PD1_RED_LED));
        break;
    }
    return led;
}