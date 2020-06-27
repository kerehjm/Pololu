/* 
* ButtonA.cpp
*
* Created: 15/05/2020 22:39:13
* Author: Mathew.Kuloba
*/


#include "buttonA.h"

// default constructor
ButtonA::ButtonA()
{
    pin = PinFactory::create(ePinId::PC0_SENSOR0);
    PCMSK0 |= (1 << PCINT1);
} //ButtonA

// default destructor
ButtonA::~ButtonA()
{
} //~ButtonA

