/* 
* Led.cpp
*
* Created: 13/05/2020 08:10:13
* Author: Mathew.Kuloba
*/

#include <stdint.h>
#include "iPinHw.hpp"
#include "iLed.hpp"
#include "led.hpp"

Led::~Led()
{
    //delete(ledPin); TODO investigate how to free
} //~Led

Led::Led(iPinHw *ledPin)
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

