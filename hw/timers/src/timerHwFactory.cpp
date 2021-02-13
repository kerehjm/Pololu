#include <stdint.h>
#include <avr/io.h>
#include "iTimerHw.hpp"
#include "timerHw.hpp"

iTimerHw * iTimerHw::createCounter(eTimerHwId hwTimerId, uint16_t frequency, void (*callback)(void))
{
    iTimerHw * timer = nullptr;
    registers_t reg0 = {
        (uint16_t*)(&OCR0A), (uint16_t*)(&OCR0B), (uint16_t*)(&TCNT0), &TCCR0A, &TCCR0B
    };
    registers_t reg1 = {
        &OCR1A, &OCR1B, &TCNT1, &TCCR1A, &TCCR1B,
    };
    registers_t reg2 = {
        (uint16_t*)(&OCR2A), (uint16_t*)(&OCR2B), (uint16_t*)(&TCNT2), &TCCR2A, &TCCR2B
    };
    switch (hwTimerId)
    {
    case eTimerHwId::tmr0:
        timer = new TimerHw( reg0,
                             normalCompare, normalCompare,
                             ctc, noPreScaler, timer0_compa, frequency, callback);
        break;
    case eTimerHwId::tmr1:
        timer = new TimerHw( reg1,
                             normalCompare, normalCompare,
                             ctc, prescaler256, timer1_compa, frequency, callback);
        break;
    case eTimerHwId::tmr2:
        timer = new TimerHw( reg2,
                             normalCompare, normalCompare,
                             normalGeneration, prescaler8, timer2_compa, frequency, callback);
        break;
    default:
        break;
    }
    return timer;
}

iTimerHw * iTimerHw::createPwm(eTimerHwId hwTimerId, void (*callback)(void))
{
    // iTimerHw * timer = new iTimerHw();
    return nullptr;
}