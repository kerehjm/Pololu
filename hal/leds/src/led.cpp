/* 
* Led.cpp
*
* Created: 13/05/2020 08:10:13
* Author: Mathew.Kuloba
*/


#include "led.h"

Led::~Led()
{
    delete(ledPin);
} //~Led

Led::Led(iPin *ledPin)
{
    this->ledPin = ledPin;
    this->off();
}

void Led::off()
{
    ledPin->reset();
}

void Led::on()
{
    ledPin->set();
}

void Led::toggle()
{
    ledPin->toggle();
}

