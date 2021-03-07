#include <stdint.h>
#include "iTimerHwData.hpp"
#include "timerHwData.hpp"

template<class T, class P>
TimerHwData<T, P>::~TimerHwData()
{

}

template<class T, class P>
TimerHwData<T, P>::TimerHwData(
    volatile T * ocra,
    volatile T * ocrb,
    volatile T * tcnt,
    volatile uint8_t * tccra,
    volatile uint8_t * tccrb,
    volatile uint8_t * timsk)
{
    this->ocra = ocra;
    this->ocrb = ocrb;
    this->tcnt = tcnt;
    this->tccra = tccra;
    this->tccrb = tccrb;
    this->timsk = timsk;

    *(this->ocra ) = 0;
    *(this->ocrb ) = 0;
    *(this->tcnt ) = 0;
    *(this->tccra) = 0;
    *(this->tccrb) = 0;
    *(this->timsk) = 0;

    // this->prescaler = P::noClkSrc;
};

template<class T, class P>
void TimerHwData<T, P>::setOcra(T ocra)
{
    *(this->ocra) = ocra;
}

template<class T, class P>
void TimerHwData<T, P>::setOcrb(T ocrb)
{ 
    *(this->ocrb) = ocrb;
}

template<class T, class P>
void TimerHwData<T, P>::setTcnt(T tcnt)
{ 
    *(this->tcnt) = tcnt;
}

template<class T, class P>
void TimerHwData<T, P>::setTccra(uint8_t tccra)
{
    *(this->tccra) = tccra;
}

template<class T, class P>
void TimerHwData<T, P>::setTccrb(uint8_t tccrb)
{
    *(this->tccrb) = tccrb;
}

template<class T, class P>
void TimerHwData<T, P>::setTimsk(uint8_t timsk)
{
    *(this->timsk) = timsk;
}

template<class T, class P>
void TimerHwData<T, P>::setPrescaler(P prescaler)
{
    this->prescaler = prescaler;
}

template<class T, class P>
T TimerHwData<T, P>::getOcra()
{
    return *(this->ocra);
}

template<class T, class P>
T TimerHwData<T, P>::getOcrb()
{
    return *(this->ocrb);
}

template<class T, class P>
T TimerHwData<T, P>::getTcnt()
{
    return *(this->tcnt);
}

template<class T, class P>
uint8_t TimerHwData<T, P>::getTccra()
{
    return *(this->tccra);
}

template<class T, class P>
uint8_t TimerHwData<T, P>::getTccrb()
{
    return *(this->tccrb);
}

template<class T, class P>
uint8_t TimerHwData<T, P>::getTimsk()
{
    return *(this->timsk);
}

template<class T, class P>
P TimerHwData<T, P>::getPrescaler()
{
    return this->prescaler;
}

template class TimerHwData<uint16_t, ePrescaler>;
template class TimerHwData<uint16_t, ePrescaler_ext>;
template class TimerHwData<uint8_t, ePrescaler>;
template class TimerHwData<uint8_t, ePrescaler_ext>;
