/* 
* ButtonC.cpp
*
* Created: 16/05/2020 00:10:24
* Author: Mathew.Kuloba
*/


#include "buttonC.h"

// default constructor
ButtonC::ButtonC()
{
    pin = PinFactory::create(ePinId::PC0_SENSOR0);
    PCMSK0 |= (1 << PCINT5);
} //ButtonC

// default destructor
ButtonC::~ButtonC()
{
} //~ButtonC
