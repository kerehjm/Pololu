#include <stdint.h>
#include "iTimerHw.hpp"
#include "iTimer.hpp"
#include "timer.hpp"

template <>
iTimer<uint16_t> * iTimer<uint16_t>::create(eTimerId timerId, void (*callback)(void))
{
    static const uint16_t frequency = 55; //1hz
    iTimer<uint16_t> * timer = nullptr;

    switch (timerId)
    {
    case eTimerId::counter:
        timer = new Timer<uint16_t>(iTimerHw<uint16_t>::createCounter_FastPwm(eTimerHwIdU16::tmr1, frequency, callback));
        break;
    case eTimerId::counter_2:
        timer = new Timer<uint16_t>(iTimerHw<uint16_t>::createCounter_FastPwm(eTimerHwIdU16::tmr1, frequency, callback));
        break;
    default:
        break;
    }
    return timer;
}