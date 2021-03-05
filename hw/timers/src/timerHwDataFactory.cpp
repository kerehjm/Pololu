#include "iTimerHw.hpp"
#include "iTimerHwData.hpp"

template<class T, class P>
iTimerHwData<T, P> * iTimerHwData<T, P>::create(eTimerHwId hwId)
{
    // switch (hwId)
    // {
    //     registers_t reg0 = {
    //     (uint16_t*)(&OCR0A), (uint16_t*)(&OCR0B), (uint16_t*)(&TCNT0), &TCCR0A, &TCCR0B
    //     };
    //     registers_t reg1 = {
    //         &OCR1A, &OCR1B, &TCNT1, &TCCR1A, &TCCR1B,
    //     };
    //     registers_t reg2 = {
    //         (uint16_t*)(&OCR2A), (uint16_t*)(&OCR2B), (uint16_t*)(&TCNT2), &TCCR2A, &TCCR2B
    //     };

    // }
}