#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "iTimerHwData.hpp"
#include "iTimerHw.hpp"
#include "timerHw.hpp"

template<class T, class P, class W>
TimerHw<T, P, W> * TimerHw<T, P, W>::vector_table[static_cast<uint8_t>(eInterruptId::max)] = {nullptr};


// default constructor
template<class T, class P, class W>
TimerHw<T, P, W>::TimerHw(
                iTimerHwData<T, P> * registers,
                eoutputCompareMode AcompareMode,
                eoutputCompareMode BcompareMode,
                W eWavegen,
                P prescaler,
                eInterruptId intId,
                T frequency,
                void(*isr)(void))
{
    this->registers = registers;
    this->registers->setOcra(frequency);
    this->registers->setOcrb(frequency);
    this->registers->setPrescaler(prescaler);

    selectCompareOutputMode(eOutput::A, AcompareMode);
    selectCompareOutputMode(eOutput::B, BcompareMode);
    selectWaveGenerationMode(eWavegen);
 
    TimerHw::vector_table[static_cast<uint8_t>(intId)] = this;
    this->handler = isr;
    this->registers->setTimsk(this->registers->getTimsk() | (1 << 1));

    sei(); //  Enable global interrupts
}

// default destructor
template<class T, class P, class W>
TimerHw<T, P, W>::~TimerHw()
{
}

template<class T, class P, class W>
void TimerHw<T, P, W>::start()
{
    selectClock(this->registers->getPrescaler());
}

template<class T, class P, class W>
void TimerHw<T, P, W>::startInverted()
{
    selectClock(this->registers->getPrescaler());
}

template<class T, class P, class W>
void TimerHw<T, P, W>::stop()
{
    selectClock(P::noClkSrc);
}

template<class T, class P, class W>
void TimerHw<T, P, W>::setTop(T top)
{
    this->registers->setOcra(top);
}
template<class T, class P, class W>
void TimerHw<T, P, W>::setReload(T reload)
{
    this->registers->setOcrb(reload);
}

template<class T, class P, class W>
T TimerHw<T, P, W>::getCount()
{
    return this->registers->getTcnt();
}

//Private function
template<class T, class P, class W>
void TimerHw<T, P, W>::selectClock(P clockSource)
{
    this->registers->setTccrb((this->registers->getTccrb() & 0b11111000) | static_cast<uint8_t>(clockSource));
}

template<class T, class P, class W>
void TimerHw<T, P, W>::selectCompareOutputMode(eOutput output, eoutputCompareMode compareMode)
{
    if (output == eOutput::A)
    {
        this->registers->setTccra((this->registers->getTccra() & 0b00111111) | (static_cast<uint8_t>(compareMode) << 6));
    }
    else
    {
        this->registers->setTccra((this->registers->getTccra() & 0b11001111) | (static_cast<uint8_t>(compareMode) << 4));
    }
}

template<class T, class P, class W>
void TimerHw<T, P, W>::selectWaveGenerationMode(W eWavegen)
{
    this->registers->setTccra((this->registers->getTccra() & 0b11111100) | ((static_cast<uint8_t>(eWavegen)) & 0b00000011));
    this->registers->setTccrb((this->registers->getTccrb() & 0b11100111) | (((static_cast<uint8_t>(eWavegen)) << 1) & 0b00011000));
}

template<class T, class P, class W>
void TimerHw<T, P, W>::intHandler(eInterruptId intId)
{
    if (handler != nullptr)
    {
        handler();
    }
}

void TIMER0_COMPA_vect(void)
{
    TimerHw<uint8_t, ePrescaler_ext, eWaveGenerationMode_Tmr0>::vector_table[0]->intHandler(eInterruptId::timer0_compa);
}

void TIMER1_COMPA_vect(void)
{
    TimerHw<uint16_t, ePrescaler_ext, eWaveGenerationMode>::vector_table[1]->intHandler(eInterruptId::timer1_compa);
}

void TIMER2_COMPA_vect(void)
{
    TimerHw<uint8_t, ePrescaler, eWaveGenerationMode_Tmr0>::vector_table[2]->intHandler(eInterruptId::timer2_compa);
}

void TIMER0_COMPB_vect(void)
{
    TimerHw<uint8_t, ePrescaler_ext, eWaveGenerationMode_Tmr0>::vector_table[3]->intHandler(eInterruptId::timer0_compb);
}

void TIMER1_COMPB_vect(void)
{
    TimerHw<uint16_t, ePrescaler_ext, eWaveGenerationMode>::vector_table[4]->intHandler(eInterruptId::timer1_compb);
}

void TIMER2_COMPB_vect(void)
{
    TimerHw<uint8_t, ePrescaler, eWaveGenerationMode_Tmr0>::vector_table[5]->intHandler(eInterruptId::timer2_compb);
}

template class TimerHw<uint16_t, ePrescaler_ext, eWaveGenerationMode>;
template class TimerHw<uint16_t, ePrescaler_ext, eWaveGenerationMode_Tmr0>;
template class TimerHw<uint16_t, ePrescaler, eWaveGenerationMode_Tmr0>;
template class TimerHw<uint8_t, ePrescaler, eWaveGenerationMode_Tmr0>;
template class TimerHw<uint8_t, ePrescaler_ext, eWaveGenerationMode>;
template class TimerHw<uint8_t, ePrescaler_ext, eWaveGenerationMode_Tmr0>;
