#include <stdint.h>
#include "iTimerHw.hpp"
#include "iTimer.hpp"
#include "timer.hpp"

template <>
iTimer<uint16_t> * iTimer<uint16_t>::create(void (*callback)(void))
{
    static const uint16_t frequency = 19530; //1hz
    iTimer<uint16_t> * timer = new Timer<uint16_t>(iTimerHw<uint16_t>::createCounter_FastPwm(eTimerHwIdU16::tmr1, frequency, callback));
    return timer;
}

template <>
iTimer<uint8_t> * iTimer<uint8_t>::createU8(eTimerIdU8 timerId, void (*callback)(void))
{
    static const uint8_t frequency = 243; //40hz
    iTimer<uint8_t> * timer = nullptr;

    switch (timerId)
    {
    case eTimerIdU8::counter_1:
        timer = new Timer<uint8_t>(iTimerHw<uint8_t>::createCounter_FastPwm(eTimerHwIdU8::tmr0, frequency, callback));
        break;
    case eTimerIdU8::counter_2:
        timer = new Timer<uint8_t>(iTimerHw<uint8_t>::createCounter_FastPwm(eTimerHwIdU8::tmr2, frequency, callback));
        break;
    default:
        break;
    }
    return timer;
}
