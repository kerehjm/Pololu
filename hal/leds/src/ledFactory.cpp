#include <stdint.h>
#include "iPin.hpp"
#include "iLed.hpp"
#include "led.hpp"

iLed * iLed::create(eLedId ledId)
{
    iLed * led = nullptr;
    iPin * ledPin = nullptr;
    if (eLedId::green == ledId)
    {
        ledPin = iPin::create(ePinId::PD7_GREEN_LED, ePinDir::OUTPUT, ePinState::LOW);
    }
    else
    {
        ledPin = iPin::create(ePinId::PD1_RED_LED, ePinDir::OUTPUT, ePinState::LOW);
    }
    led = new Led(ledPin);
    return led;
}