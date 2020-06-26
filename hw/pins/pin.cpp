/* 
* Pin.cpp
*
* Created: 12/05/2020 15:19:01
* Author: Mathew.Kuloba
*/

#include "pin.h"

Pin::Pin()
{
    
}
Pin::~Pin()
{
} //~Pin

Pin::Pin(PinPortMap pin, ePinDir dir, ePinState state)
{
    this->pin = pin;

    setDir(dir);
    setState(state);
}

void Pin::set()
{
    *pin.port |= (1 << pin.num);
}

void Pin::reset()
{
    *pin.port &= ~(1 << pin.num);
}

void Pin::toggle()
{
    *pin.port ^= (1 << pin.num);
}

void Pin::input()
{
    *pin.ddr &= ~(1 << pin.num);
}

void Pin::output()
{
    *pin.ddr |= (1 << pin.num);
}

bool Pin::is_pin_set()
{
    return (*pin.port & (1 << pin.num));
}

void Pin::setDir(ePinDir dir)
{
    if (dir == ePinDir::INPUT)
    {
        input();
    }
    else
    {
        output();
    }
}

void Pin::setState(ePinState state)
{
    if (state == ePinState::HIGH)
    {
        set();
    }
    else
    {
        reset();
    }
}
