#include <stdint.h>
#include <avr/io.h>
#include "iTimerHwData.hpp"
#include "timerHwData.hpp"

template<>
iTimerHwData<uint8_t, ePrescaler_ext> * iTimerHwData<uint8_t, ePrescaler_ext>::createTimer0()
{
    return new TimerHwData<uint8_t, ePrescaler_ext>(&OCR0A, &OCR0B, &TCNT0, &TCCR0A, &TCCR0B, &TIMSK0);
}

template<>
iTimerHwData<uint16_t, ePrescaler_ext> * iTimerHwData<uint16_t, ePrescaler_ext>::createTimer1()
{
    return new TimerHwData<uint16_t, ePrescaler_ext>(&OCR1A, &OCR1B, &TCNT1, &TCCR1A, &TCCR1B, &TIMSK1);
}

template<>
iTimerHwData<uint8_t, ePrescaler> * iTimerHwData<uint8_t, ePrescaler>::createTimer2()
{
    return new TimerHwData<uint8_t, ePrescaler>(&OCR2A, &OCR2B, &TCNT2, &TCCR2A, &TCCR2B, &TIMSK2);
}

template iTimerHwData<uint8_t, ePrescaler_ext> * iTimerHwData<uint8_t, ePrescaler_ext>::createTimer0();
template iTimerHwData<uint16_t, ePrescaler_ext> * iTimerHwData<uint16_t, ePrescaler_ext>::createTimer1();
template iTimerHwData<uint8_t, ePrescaler> * iTimerHwData<uint8_t, ePrescaler>::createTimer2();
