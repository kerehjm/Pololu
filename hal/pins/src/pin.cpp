/* 
* Pin.cpp
*
* Created: 12/05/2020 15:19:01
* Author: Mathew.Kuloba
*/

#include <stdint.h>
#include "iPin.hpp"
#include "iPinHw.hpp"
#include "pin.hpp"

Pin::Pin()
{
    
}
Pin::~Pin()
{
} //~Pin

Pin::Pin(ePinId pinId)
{
    pin = pinId;
}

void Pin::set()
{

}

void Pin::reset()
{
}

void Pin::toggle()
{
}

void Pin::input()
{
}

void Pin::output()
{
}

bool Pin::is_pin_set()
{
    return 0;
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
