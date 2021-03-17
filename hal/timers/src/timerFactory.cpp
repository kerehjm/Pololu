#include <stdint.h>
#include "iTimerHw.hpp"
#include "iTimer.hpp"
#include "timer.hpp"

template <>
iTimer<uint16_t> * iTimer<uint16_t>::create(void (*callback)(void))
{
    static const uint16_t frequency = 9764; //1hz
    iTimer<uint16_t> * timer = new Timer<uint16_t>(iTimerHw<uint16_t>::createCounter_FastPwm(eTimerHwIdU16::tmr1, frequency, callback));
    return timer;
}