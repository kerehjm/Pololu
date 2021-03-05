#include <stdint.h>
#include <avr/io.h>
#include "iTimerHw.hpp"
#include "iTimerHwData.hpp"
#include "timerHw.hpp"

template<class T>
iTimerHw<T> * iTimerHw<T>::createCounter_CTC(eTimerHwId hwTimerId, T frequency, void (*callback)(void))
{
    iTimerHw<T> * timer = nullptr;

    switch (hwTimerId)
    {
    case eTimerHwId::tmr0:
        timer = new TimerHw<uint8_t, ePrescaler_ext, eWaveGenerationMode_Tmr0>(
                            iTimerHwData<uint8_t, ePrescaler_ext>::create(hwTimerId),
                            eoutputCompareMode::normalCompare,
                            eoutputCompareMode::normalCompare,
                            eWaveGenerationMode_Tmr0::ctc,
                            ePrescaler_ext::prescaler256,
                            eInterruptId::timer0_compa,
                            frequency,
                            callback);
        break;
    case eTimerHwId::tmr1:
        timer = new TimerHw<uint16_t, ePrescaler_ext, eWaveGenerationMode>(
                            iTimerHwData<uint16_t, ePrescaler_ext>::create(hwTimerId),
                            eoutputCompareMode::normalCompare,
                            eoutputCompareMode::normalCompare,
                            eWaveGenerationMode::ctc,
                            ePrescaler_ext::prescaler256,
                            eInterruptId::timer1_compa,
                            frequency,
                            callback);
        break;
    case eTimerHwId::tmr2:
        timer = new TimerHw<uint8_t, ePrescaler, eWaveGenerationMode_Tmr0>(
                            iTimerHwData<uint8_t, ePrescaler>::create(hwTimerId),
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

template<class T>
iTimerHw<T> * iTimerHw<T>::createCounter_FastPwm(eTimerHwId hwTimerId, T frequency, void (*callback)(void))
{
    iTimerHw<T> * timer = nullptr;

    switch (hwTimerId)
    {
    case eTimerHwId::tmr0:
        timer = new TimerHw<uint8_t, ePrescaler_ext, eWaveGenerationMode_Tmr0>(
                            iTimerHwData<uint8_t, ePrescaler_ext>::create(hwTimerId),
                            eoutputCompareMode::normalCompare,
                            eoutputCompareMode::normalCompare,
                            eWaveGenerationMode_Tmr0::fastPwm,
                            ePrescaler_ext::prescaler256,
                            eInterruptId::timer0_compa,
                            frequency,
                            callback);
        break;
    case eTimerHwId::tmr1:
        timer = new TimerHw<uint16_t, ePrescaler_ext, eWaveGenerationMode>(
                            iTimerHwData<uint16_t, ePrescaler_ext>::create(hwTimerId),
                            eoutputCompareMode::normalCompare,
                            eoutputCompareMode::normalCompare,
                            eWaveGenerationMode::fastPwm,
                            ePrescaler_ext::prescaler256,
                            eInterruptId::timer1_compa,
                            frequency,
                            callback);
        break;
    case eTimerHwId::tmr2:
        timer = new TimerHw<uint8_t, ePrescaler, eWaveGenerationMode_Tmr0>(
                            iTimerHwData<uint8_t, ePrescaler>::create(hwTimerId),
                            eoutputCompareMode::normalCompare,
                            eoutputCompareMode::normalCompare,
                            eWaveGenerationMode_Tmr0::fastPwm,
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

template<class T>
iTimerHw<T> * iTimerHw<T>::createPwm(eTimerHwId hwTimerId, T frequency)
{
    iTimerHw<T> * timer = nullptr;

    switch (hwTimerId)
    {
    case eTimerHwId::tmr0:
        timer = new TimerHw<uint8_t, ePrescaler_ext, eWaveGenerationMode_Tmr0>(
                            iTimerHwData<uint8_t, ePrescaler_ext>::create(hwTimerId),
                            eoutputCompareMode::setOnCompare,
                            eoutputCompareMode::normalCompare,
                            eWaveGenerationMode_Tmr0::pwmPhaseCorrect,
                            ePrescaler_ext::prescaler1024,
                            eInterruptId::timer0_compa,
                            frequency);
        break;
    case eTimerHwId::tmr1:
        timer = new TimerHw<uint16_t, ePrescaler_ext, eWaveGenerationMode>(
                            iTimerHwData<uint16_t, ePrescaler_ext>::create(hwTimerId),
                            eoutputCompareMode::setOnCompare,
                            eoutputCompareMode::normalCompare,
                            eWaveGenerationMode::fastPwm,
                            ePrescaler_ext::prescaler256, eInterruptId::timer1_compa, frequency, nullptr);
        break;
    case eTimerHwId::tmr2:
        timer = new TimerHw<uint8_t, ePrescaler, eWaveGenerationMode_Tmr0>(
                            iTimerHwData<uint8_t, ePrescaler>::create(hwTimerId),
                            eoutputCompareMode::setOnCompare,
                            eoutputCompareMode::normalCompare,
                            eWaveGenerationMode_Tmr0::pwmPhaseCorrect,
                            ePrescaler::prescaler1024,
                            eInterruptId::timer2_compa,
                            frequency);
        break;
    default:
        break;
    }

    return timer;
}
