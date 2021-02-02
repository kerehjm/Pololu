#include <stdint.h>
#include <avr/io.h>
#include "iTimerHw.hpp"
#include "timerHw.hpp"

iTimerHw * iTimerHw::createCounter(eTimerHwId hwTimerId)
{
    iTimerHw * timer = nullptr;
    switch (hwTimerId)
    {
    case eTimerHwId::tmr0:
        timer = new TimerHw(&OCR0A, &OCR0B, &TCNT0, &TCCR0A, &TCCR0B,
                             eoutputCompareMode::normalCompare, eoutputCompareMode::normalCompare,
                             eWaveGenerationMode::normalGeneration, prescaler8);
        break;
    // case eTimerHwId::tmr1:
    //     timer = new TimerHw(&OCR1A, &OCR1B, &TCNT1, &TCCR1A, &TCCR1B,
    //                          eoutputCompareMode::normalCompare, eoutputCompareMode::normalCompare,
    //                          eWaveGenerationMode::normalGeneration, prescaler8);
    //     break;
    case eTimerHwId::tmr2:
        timer = new TimerHw(&OCR2A, &OCR2B, &TCNT2, &TCCR2A, &TCCR2B,
                             eoutputCompareMode::normalCompare, eoutputCompareMode::normalCompare,
                             eWaveGenerationMode::normalGeneration, ePrescaler::prescaler8);
        break;
    default:
        break;
    }
    return timer;
}

iTimerHw * iTimerHw::createPwm(eTimerHwId hwTimerId)
{
    // iTimerHw * timer = new iTimerHw();
    return nullptr;
}