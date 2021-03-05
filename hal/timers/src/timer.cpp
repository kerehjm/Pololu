/* 
* timer.cpp
*
* Created: 15/05/2020 16:30:39
* Author: Mathew.Kuloba
*/

#include <stdint.h>
#include "iTimer.hpp"
#include "iTimerHw.hpp"
#include "timer.hpp"

// default constructor
Timer::Timer(iTimerHw<uint16_t> * timerHw)
{
    this->timerHw = timerHw;
}

// default destructor
Timer::~Timer()
{
    delete(timerHw);
} //~Timer

void Timer::start()
{
    timerHw->start();
}

void Timer::stop()
{
    timerHw->stop();
}

void Timer::setFrequency(uint16_t frequency)
{
    timerHw->setTop(frequency);
}

void Timer::setDutyCycle(uint16_t dutyCycle)
{
    timerHw->setReload(dutyCycle);
}

uint16_t Timer::getCount()
{
    uint16_t count = 0;
    timerHw->getCount(count);
    return count;
}
