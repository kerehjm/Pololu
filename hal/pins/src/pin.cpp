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

Pin::~Pin()
{
} //~Pin

Pin::Pin(ePinId pinId, iPinHw * pinHw, ePinDir pinDir, ePinState pinState)
{
    this->pinId = pinId;
    this->pinHw = pinHw;

    // update hw state
    if (ePinDir::OUTPUT == pinDir)
    {
        pinHw->output();
    } 
    else 
    {
        pinHw->input();
    }
    if (ePinState::HIGH == pinState)
    {
        pinHw->set();
    } 
    else 
    {
        pinHw->reset();
    }
}

inline void Pin::set()
{
    pinHw->set();
}

inline void Pin::reset()
{
    pinHw->reset();
}

inline void Pin::toggle()
{
    pinHw->toggle();
}

inline void Pin::input()
{
    pinHw->input();
}

inline void Pin::output()
{
    pinHw->output();
}

inline bool Pin::isSet()
{
    return pinHw->isSet();
}
