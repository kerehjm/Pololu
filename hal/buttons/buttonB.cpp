/* 
* ButtonB.cpp
*
* Created: 16/05/2020 00:10:11
* Author: Mathew.Kuloba
*/


#include "buttonB.h"

// default constructor
ButtonB::ButtonB()
{
    pin = PinFactory::create(ePinId::PC0_SENSOR0);
    PCMSK0 |= (1 << PCINT4);
} //ButtonB

// default destructor
ButtonB::~ButtonB()
{
} //~ButtonB
