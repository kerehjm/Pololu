#include <stdint.h>
#include "iTimerHw.hpp"
#include "iPwm.hpp"
#include "pwm.hpp"

iPwm * iPwm::create(ePwmId pwmId)
{
    static const uint8_t dc = 1;
    iPwm * pwm = nullptr;

    switch (pwmId)
    {
    case ePwmId::pwm_1:
        pwm = new Pwm(iTimerHw<uint8_t>::createPwm(eTimerHwIdU8::tmr0, dc));
        break;
    case ePwmId::pwm_2:
        pwm = new Pwm(iTimerHw<uint8_t>::createPwm(eTimerHwIdU8::tmr2, dc));
        break;
    default:
        break;
    }
    return pwm;
}