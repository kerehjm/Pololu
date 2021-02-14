#include <stdint.h>
#include "iTimerHw.hpp"
#include "iTimer.hpp"
#include "timer.hpp"

iTimer * iTimer::create(eTimerId timerId, void (*callback)(void))
{
    static const uint16_t frequency = 39061; //1hz
    static const uint16_t frequency2 = 50; //1hz
    iTimer * timer = nullptr;
    iTimerHw * timerHw = nullptr;
    switch (timerId)
    {
    case eTimerId::counter:
        timerHw = iTimerHw::createCounter_CTC(eTimerHwId::tmr1, frequency, callback);
        timer = new Timer(timerHw);
        break;
    case eTimerId::counter_2:
        timerHw = iTimerHw::createCounter_FastPwm(eTimerHwId::tmr1, frequency, callback);
        timer = new Timer(timerHw);
        break;
    case eTimerId::pwm:
        timerHw = iTimerHw::createPwm(eTimerHwId::tmr0, frequency2);
        timer = new Timer(timerHw);
        break;
    case eTimerId::pwm2:
        timerHw = iTimerHw::createPwm(eTimerHwId::tmr2, frequency2);
        timer = new Timer(timerHw);
        break;
    default:
        break;
    }
    return timer;
}