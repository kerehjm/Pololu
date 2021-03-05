#include <stdint.h>
#include "iTimerHw.hpp"
#include "iTimer.hpp"
#include "timer.hpp"

iTimer * iTimer::create(eTimerId timerId, void (*callback)(void))
{
    static const uint16_t frequency = 55; //1hz
    iTimer * timer = nullptr;
    iTimerHw<uint16_t> * timerHw = nullptr;
    switch (timerId)
    {
    case eTimerId::counter:
        timerHw = iTimerHw<uint16_t>::createCounter_FastPwm(eTimerHwId::tmr1, frequency, callback);
        timer = new Timer(timerHw);
        break;
    case eTimerId::counter_2:
        timerHw = iTimerHw<uint16_t>::createCounter_FastPwm(eTimerHwId::tmr1, frequency, callback);
        timer = new Timer(timerHw);
        break;
    case eTimerId::pwm:
        timerHw = iTimerHw<uint16_t>::createPwm(eTimerHwId::tmr1, frequency);
        timer = new Timer(timerHw);
        break;
    case eTimerId::pwm2:
        timerHw = iTimerHw<uint16_t>::createPwm(eTimerHwId::tmr1, frequency);
        timer = new Timer(timerHw);
        break;
    default:
        break;
    }
    return timer;
}