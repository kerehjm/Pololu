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

inline void PinHw::set()
{
    *pinPortMap->port |= (1U << pinPortMap->num);
}

inline void PinHw::reset()
{
    *pinPortMap->port &= ~(1U << pinPortMap->num);
}

inline void PinHw::toggle()
{
    *pinPortMap->port ^= (1U << pinPortMap->num);
}

inline void PinHw::output()
{
    *pinPortMap->ddr |= (1U << pinPortMap->num);
}

inline void PinHw::input()
{
    *pinPortMap->ddr &= ~(1U << pinPortMap->num);
}

inline bool PinHw::isSet()
{
    return (*pinPortMap->port & (1U << pinPortMap->num));
}
