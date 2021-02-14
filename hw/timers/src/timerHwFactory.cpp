#include <stdint.h>
#include <avr/io.h>
#include "iTimerHw.hpp"
#include "timerHw.hpp"

iTimerHw * iTimerHw::createCounter_CTC(eTimerHwId hwTimerId, uint16_t frequency, void (*callback)(void))
{
    iTimerHw * timer = nullptr;
    registers_t reg = getRegisters(hwTimerId);

    switch (hwTimerId)
    {
    case eTimerHwId::tmr0:
        timer = new TimerHw( reg,
                             eoutputCompareMode::setOnCompare, eoutputCompareMode::setOnCompare,
                             static_cast<eWaveGenerationMode>(eWaveGenerationMode_Tmr0::ctc), static_cast<ePrescaler>(ePrescaler_ext::prescaler256), eInterruptId::timer0_compa, frequency, callback);
        break;
    case eTimerHwId::tmr1:
        timer = new TimerHw( reg,
                             eoutputCompareMode::setOnCompare, eoutputCompareMode::setOnCompare,
                             eWaveGenerationMode::ctc, static_cast<ePrescaler>(ePrescaler_ext::prescaler256), eInterruptId::timer1_compa, frequency, callback);
        break;
    case eTimerHwId::tmr2:
        timer = new TimerHw( reg,
                             eoutputCompareMode::setOnCompare, eoutputCompareMode::setOnCompare,
                             static_cast<eWaveGenerationMode>(eWaveGenerationMode_Tmr0::ctc), ePrescaler::prescaler256, eInterruptId::timer2_compa, frequency, callback);
        break;
    default:
        break;
    }
    return timer;
}

iTimerHw * iTimerHw::createCounter_FastPwm(eTimerHwId hwTimerId, uint16_t frequency, void (*callback)(void))
{
    iTimerHw * timer = nullptr;
    registers_t reg = getRegisters(hwTimerId);

    switch (hwTimerId)
    {
    case eTimerHwId::tmr0:
        timer = new TimerHw( reg,
                             eoutputCompareMode::setOnCompare, eoutputCompareMode::setOnCompare,
                             static_cast<eWaveGenerationMode>(eWaveGenerationMode_Tmr0::fastPwm), static_cast<ePrescaler>(ePrescaler_ext::prescaler256), eInterruptId::timer0_compa, frequency, callback);
        break;
    case eTimerHwId::tmr1:
        timer = new TimerHw( reg,
                             eoutputCompareMode::setOnCompare, eoutputCompareMode::setOnCompare,
                             eWaveGenerationMode::fastPwm, static_cast<ePrescaler>(ePrescaler_ext::prescaler256), eInterruptId::timer1_compa, frequency, callback);
        break;
    case eTimerHwId::tmr2:
        timer = new TimerHw( reg,
                             eoutputCompareMode::setOnCompare, eoutputCompareMode::setOnCompare,
                             static_cast<eWaveGenerationMode>(eWaveGenerationMode_Tmr0::fastPwm), ePrescaler::prescaler256, eInterruptId::timer2_compa, frequency, callback);
        break;
    default:
        break;
    }
    return timer;
}

iTimerHw * iTimerHw::createPwm(eTimerHwId hwTimerId, uint16_t frequency)
{
    iTimerHw * timer = nullptr;
    registers_t reg = getRegisters(hwTimerId);

    switch (hwTimerId)
    {
    case eTimerHwId::tmr0:
        timer = new TimerHw( reg,
                             eoutputCompareMode::setOnCompare, eoutputCompareMode::normalCompare,
                             static_cast<eWaveGenerationMode>(eWaveGenerationMode_Tmr0::pwmPhaseCorrect), static_cast<ePrescaler>(ePrescaler_ext::prescaler1024), eInterruptId::timer0_compa, frequency);
        break;
    case eTimerHwId::tmr1:
        timer = new TimerHw( reg,
                             eoutputCompareMode::setOnCompare, eoutputCompareMode::normalCompare,
                             eWaveGenerationMode::fastPwm, static_cast<ePrescaler>(ePrescaler_ext::prescaler256), eInterruptId::timer1_compa, frequency);
        break;
    case eTimerHwId::tmr2:
         timer = new TimerHw( reg,
                             eoutputCompareMode::setOnCompare, eoutputCompareMode::normalCompare,
                             static_cast<eWaveGenerationMode>(eWaveGenerationMode_Tmr0::pwmPhaseCorrect), ePrescaler::prescaler1024, eInterruptId::timer2_compa, frequency);
        break;
    default:
        break;
    }

    return timer;
}

registers_t iTimerHw::getRegisters(eTimerHwId hwTimerId)
{
    registers_t reg;
    switch (hwTimerId)
    {
    case eTimerHwId::tmr0:
        reg = registers_t(&OCR0A, &OCR0B, &TCNT0, &TCCR0A, &TCCR0B);
        break;
    case eTimerHwId::tmr1:
        reg = registers_t(reinterpret_cast<volatile uint8_t *>(&OCR1A), reinterpret_cast<volatile uint8_t *>(&OCR1B), reinterpret_cast<volatile uint8_t *>(&TCNT1), &TCCR1A, &TCCR1B);
        break;
    case eTimerHwId::tmr2:
        reg = registers_t(&OCR2A, &OCR2B, &TCNT2, &TCCR2A, &TCCR2B);
        break;
    default:
        break;
    }
    return reg;
}