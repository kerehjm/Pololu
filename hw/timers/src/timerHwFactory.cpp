#include <stdint.h>
#include <avr/io.h>
#include "iTimerHwData.hpp"
#include "iTimerHw.hpp"
#include "timerHw.hpp"

template<>
iTimerHw<uint8_t> * iTimerHw<uint8_t>::createCounter_CTC(eTimerHwIdU8 hwTimerId, uint8_t frequency, void (*callback)(void))
{
    iTimerHw<uint8_t> * timer = nullptr;

    switch (hwTimerId)
    {
    case eTimerHwIdU8::tmr0:
        timer = new TimerHw<uint8_t, ePrescaler_ext, eWaveGenerationMode_Tmr0>(
                            iTimerHwData<uint8_t, ePrescaler_ext>::createTimer0(),
                            eoutputCompareMode::normalCompare,
                            eoutputCompareMode::normalCompare,
                            eWaveGenerationMode_Tmr0::ctc,
                            ePrescaler_ext::prescaler256,
                            eInterruptId::timer0_compa,
                            frequency,
                            callback);
        break;
    case eTimerHwIdU8::tmr2:
        timer = new TimerHw<uint8_t, ePrescaler, eWaveGenerationMode_Tmr0>(
                            iTimerHwData<uint8_t, ePrescaler>::createTimer2(),
                            eoutputCompareMode::normalCompare,
                            eoutputCompareMode::normalCompare,
                            eWaveGenerationMode_Tmr0::ctc,
                            ePrescaler::prescaler256,
                            eInterruptId::timer2_compa,
                            frequency,
                            callback);
        break;
    default:
        break;
    }
    return timer;
}

template<>
iTimerHw<uint16_t> * iTimerHw<uint16_t>::createCounter_CTC(eTimerHwIdU16 hwTimerId, uint16_t frequency, void (*callback)(void))
{
    iTimerHw<uint16_t> * timer = nullptr;

    switch (hwTimerId)
    {
    case eTimerHwIdU16::tmr1:
        timer = new TimerHw<uint16_t, ePrescaler_ext, eWaveGenerationMode>(
                            iTimerHwData<uint16_t, ePrescaler_ext>::createTimer1(),
                            eoutputCompareMode::normalCompare,
                            eoutputCompareMode::normalCompare,
                            eWaveGenerationMode::ctc,
                            ePrescaler_ext::prescaler256,
                            eInterruptId::timer1_compa,
                            frequency,
                            callback);
        break;
    default:
        break;
    }
    return timer;
}

template<>
iTimerHw<uint8_t> * iTimerHw<uint8_t>::createCounter_FastPwm(eTimerHwIdU8 hwTimerId, uint8_t frequency, void (*callback)(void))
{
    iTimerHw<uint8_t> * timer = nullptr;

    switch (hwTimerId)
    {
    case eTimerHwIdU8::tmr0:
        timer = new TimerHw<uint8_t, ePrescaler_ext, eWaveGenerationMode_Tmr0>(
                        iTimerHwData<uint8_t, ePrescaler_ext>::createTimer0(),
                        eoutputCompareMode::normalCompare,
                        eoutputCompareMode::normalCompare,
                        eWaveGenerationMode_Tmr0::fastPwm,
                        ePrescaler_ext::prescaler1024,
                        eInterruptId::timer0_compa,
                        frequency,
                        callback);
        break;
    case eTimerHwIdU8::tmr2:
        timer = new TimerHw<uint8_t, ePrescaler, eWaveGenerationMode_Tmr0>(
                            iTimerHwData<uint8_t, ePrescaler>::createTimer2(),
                            eoutputCompareMode::normalCompare,
                            eoutputCompareMode::normalCompare,
                            eWaveGenerationMode_Tmr0::fastPwm,
                            ePrescaler::prescaler1024,
                            eInterruptId::timer2_compa,
                            frequency,
                            callback);
        break;
    default:
        break;
    }
    return timer;
}

template<>
iTimerHw<uint16_t> * iTimerHw<uint16_t>::createCounter_FastPwm(eTimerHwIdU16 hwTimerId, uint16_t frequency, void (*callback)(void))
{
    iTimerHw<uint16_t> * timer = nullptr;

    switch (hwTimerId)
    {
    case eTimerHwIdU16::tmr1:
        timer = new TimerHw<uint16_t, ePrescaler_ext, eWaveGenerationMode>(
                            iTimerHwData<uint16_t, ePrescaler_ext>::createTimer1(),
                            eoutputCompareMode::normalCompare,
                            eoutputCompareMode::normalCompare,
                            eWaveGenerationMode::fastPwm,
                            ePrescaler_ext::prescaler1024,
                            eInterruptId::timer1_compa,
                            frequency,
                            callback);
        break;
    default:
        break;
    }
    return timer;
}

template<>
iTimerHw<uint8_t> * iTimerHw<uint8_t>::createPwm(eTimerHwIdU8 hwTimerId, uint8_t frequency)
{
    iTimerHw<uint8_t> * timer = nullptr;

    switch (hwTimerId)
    {
    case eTimerHwIdU8::tmr0:
        timer = new TimerHw<uint8_t, ePrescaler_ext, eWaveGenerationMode_Tmr0>(
                            iTimerHwData<uint8_t, ePrescaler_ext>::createTimer0(),
                            eoutputCompareMode::normalCompare,
                            eoutputCompareMode::normalCompare,
                            eWaveGenerationMode_Tmr0::pwmPhaseCorrect,
                            ePrescaler_ext::prescaler8,
                            eInterruptId::timer0_compa,
                            frequency);
        break;
    case eTimerHwIdU8::tmr2:
        timer = new TimerHw<uint8_t, ePrescaler, eWaveGenerationMode_Tmr0>(
                            iTimerHwData<uint8_t, ePrescaler>::createTimer2(),
                            eoutputCompareMode::normalCompare,
                            eoutputCompareMode::normalCompare,
                            eWaveGenerationMode_Tmr0::pwmPhaseCorrect,
                            ePrescaler::prescaler8,
                            eInterruptId::timer2_compa,
                            frequency);
        break;
    default:
        break;
    }
    return timer;
}

template<>
iTimerHw<uint16_t> * iTimerHw<uint16_t>::createPwm(eTimerHwIdU16 hwTimerId, uint16_t frequency)
{
    iTimerHw<uint16_t> * timer = nullptr;

    switch (hwTimerId)
    {
    case eTimerHwIdU16::tmr1:
        timer = new TimerHw<uint16_t, ePrescaler_ext, eWaveGenerationMode>(
                            iTimerHwData<uint16_t, ePrescaler_ext>::createTimer1(),
                            eoutputCompareMode::setOnCompare,
                            eoutputCompareMode::normalCompare,
                            eWaveGenerationMode::fastPwm,
                            ePrescaler_ext::prescaler256, eInterruptId::timer1_compa, frequency, nullptr);
        break;
    default:
        break;
    }
    return timer;
}

template iTimerHw<uint8_t> * iTimerHw<uint8_t>::createCounter_CTC(eTimerHwIdU8 hwTimerId, uint8_t frequency, void (*callback)(void));
template iTimerHw<uint16_t> * iTimerHw<uint16_t>::createCounter_CTC(eTimerHwIdU16 hwTimerId, uint16_t frequency, void (*callback)(void));
template iTimerHw<uint8_t> * iTimerHw<uint8_t>::createCounter_FastPwm(eTimerHwIdU8 hwTimerId, uint8_t frequency, void (*callback)(void));
template iTimerHw<uint16_t> * iTimerHw<uint16_t>::createCounter_FastPwm(eTimerHwIdU16 hwTimerId, uint16_t frequency, void (*callback)(void));
template iTimerHw<uint8_t> * iTimerHw<uint8_t>::createPwm(eTimerHwIdU8 hwTimerId, uint8_t frequency);
template iTimerHw<uint16_t> * iTimerHw<uint16_t>::createPwm(eTimerHwIdU16 hwTimerId, uint16_t frequency);
