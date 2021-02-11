#include <stdint.h>
#include "iTimerHw.hpp"
#include "iTimer.hpp"
#include "timer.hpp"

iTimer * iTimer::create(eTimerId timerId, void (*callback)(void))
{
    iTimer * timer = nullptr;
    iTimerHw * timerHw = nullptr;
    switch (timerId)
    {
    case eTimerId::counter:
        timerHw = iTimerHw::createCounter(eTimerHwId::tmr1, callback);
        timer = new Timer(timerHw);
        break;
    case eTimerId::pwm:
        timerHw = iTimerHw::createPwm(eTimerHwId::tmr2, callback);
        timer = new Timer(timerHw);
        break;
    default:
        break;
    }
    return timer;
}