#include <stdint.h>
#include <avr/io.h>
#include "iTimerHw.hpp"
#include "timerHw.hpp"

iTimerHw * iTimerHw::createCounter(eTimerHwId hwTimerId, void (*callback)(void))
{
    iTimerHw * timer = nullptr;
    switch (hwTimerId)
    {
    case eTimerHwId::tmr0:
        timer = new TimerHw((uint16_t*)(&OCR0A), (uint16_t*)(&OCR0B), (uint16_t*)(&TCNT0), &TCCR0A, &TCCR0B,
                             eoutputCompareMode::normalCompare, eoutputCompareMode::normalCompare,
                             eWaveGenerationMode::ctc, noPreScaler, eInterruptId::timer0_compa, callback);
        break;
    case eTimerHwId::tmr1:
        timer = new TimerHw(&OCR1A, &OCR1B, &TCNT1, &TCCR1A, &TCCR1B,
                             eoutputCompareMode::normalCompare, eoutputCompareMode::normalCompare,
                             eWaveGenerationMode::ctc, prescaler64, eInterruptId::timer1_compa, callback);
        break;
    case eTimerHwId::tmr2:
        timer = new TimerHw((uint16_t*)(&OCR2A), (uint16_t*)(&OCR2B), (uint16_t*)(&TCNT2), &TCCR2A, &TCCR2B,
                             eoutputCompareMode::normalCompare, eoutputCompareMode::normalCompare,
                             eWaveGenerationMode::normalGeneration, ePrescaler::prescaler8, eInterruptId::timer2_compa, callback);
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