#include <stdint.h>
#include "iTimerHw.hpp"
#include "iTimer.hpp"
#include "timer.hpp"

iTimer * iTimer::create(eTimerId timerId)
{
    iTimer * timer = nullptr;
    iTimerHw * timerHw = nullptr;
    switch (timerId)
    {
    case eTimerId::counter:
        timerHw = iTimerHw::createCounter(eTimerHwId::tmr0);
        timer = new Timer(timerHw);
        break;
    case eTimerId::pwm:
        timerHw = iTimerHw::createPwm(eTimerHwId::tmr2);
        timer = new Timer(timerHw);
        break;
    default:
        break;
    }
    return timer;
}