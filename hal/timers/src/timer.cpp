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
Timer::Timer(iTimerHw * timerHw)
{
    this->timerHw = timerHw;
}

// default destructor
Timer::~Timer()
{
    delete(timerHw);
} //~Timer

void Timer::start(uint16_t count)
{
    timerHw->start();
    timerHw->setTop(count);
}

void Timer::stop()
{
    timerHw->stop();
}

void Timer::reload(uint16_t count)
{
    timerHw->setReload(count);
}

uint8_t Timer::getCount()
{
    return timerHw->getCount();
}
