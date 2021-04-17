/* 
* PinHw.cpp
*
* Created: 12/05/2020 15:19:01
* Author: Mathew.Kuloba
*/

#include "iPinHw.hpp"
#include "pinPortMap.hpp"
#include "pinHw.hpp"

PinHw::PinHw(PinPortMap * pinPortMap)
{
    this->pinPortMap = pinPortMap;
}

PinHw::~PinHw()
{

}

void PinHw::set()
{
    *pinPortMap->port |= (1U << pinPortMap->num);
}

void PinHw::reset()
{
    *pinPortMap->port &= ~(1U << pinPortMap->num);
}

void PinHw::write(bool state)
{
    if (state == true)
    {
        set();
    }
    else
    {
        reset();
    }
}

void PinHw::toggle()
{
    *pinPortMap->port ^= (1U << pinPortMap->num);
}

void PinHw::output()
{
    *pinPortMap->ddr |= (1U << pinPortMap->num);
}

void PinHw::input()
{
    *pinPortMap->ddr &= ~(1U << pinPortMap->num);
}

bool PinHw::isSet()
{
    return (*pinPortMap->pin & (1U << pinPortMap->num));
}
