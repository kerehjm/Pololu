#include <stdint.h>
#include "iPin.hpp"
#include "iLed.hpp"
#include "led.hpp"

iLed * iLed::create(eLedId ledId)
{
    iLed * led = nullptr;
    if (eLedId::green == ledId)
    {
        iPin * ledPin = iPin::create(ePinId::PD7_GREEN_LED, ePinDir::OUTPUT, ePinState::LOW);
        (void)(ledPin);
    }
    else
    {
        iPin * ledPin = iPin::create(ePinId::PD1_RED_LED, ePinDir::OUTPUT, ePinState::LOW);
        (void)(ledPin);
    }
    (void)(led);
    return nullptr;
}