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

void Timer::start()
{
    timerHw->start();
}

void Timer::stop()
{
    timerHw->stop();
}

void Timer::reload(uint16_t count)
{
    timerHw->setReload(count);
}

uint16_t Timer::getCount()
{
    return timerHw->getCount();
}
