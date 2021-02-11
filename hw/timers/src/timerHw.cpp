#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "iTimerHw.hpp"
#include "timerHw.hpp"

uint16_t * ocra = nullptr;
uint16_t * ocrb = nullptr;

uint16_t * tcnt = nullptr;
uint8_t * tccra = nullptr;
uint8_t * tccrb = nullptr;
ePrescaler prescaler = ePrescaler::noClkSrc;

TimerHw * TimerHw::vector_table[eInterruptId::max] = {nullptr};
void (*handler)(void) = nullptr;

// default constructor
TimerHw::TimerHw(volatile uint16_t * ocra, volatile uint16_t * ocrb, volatile uint16_t * tcnt, volatile uint8_t * tccra, volatile uint8_t * tccrb,
                 eoutputCompareMode AcompareMode, eoutputCompareMode BcompareMode, eWaveGenerationMode waveGenMode, ePrescaler prescaler, eInterruptId intId, void(*isr)(void))
{
    selectCompareOutputMode(eOutput::A, AcompareMode);
    selectCompareOutputMode(eOutput::B, BcompareMode);
    selectWaveGenerationMode(waveGenMode);
    
    this->ocra = ocra;
    this->ocrb = ocrb;
    *this->ocra = *this->ocrb = 0;

    this->tccra = tccra;
    this->tccrb = tccrb;

    this->tcnt = 0;
    this->prescaler = prescaler;

    TimerHw::vector_table[intId] = this;
    this->handler = isr;

   TIMSK1 |= (1 << OCIE1A); // Enable CTC interrupt
   sei(); //  Enable global interrupts
}

// default destructor
TimerHw::~TimerHw()
{
}

void TimerHw::start()
{
    selectClock(prescaler);
}

void TimerHw::startInverted()
{
}

void TimerHw::stop()
{
    selectClock(ePrescaler::noClkSrc);
}

void TimerHw::setTop(uint8_t top)
{
    *ocra = top;
}
void TimerHw::setReload(uint8_t reload)
{
    *ocrb = reload;
}

uint8_t TimerHw::getCount()
{
    return *tcnt;
}

//Private function

void TimerHw::selectClock(ePrescaler clockSource)
{
    *tccrb = (*tccrb & 0b11111000) | clockSource;
}

void TimerHw::selectCompareOutputMode(eOutput output, eoutputCompareMode compareMode)
{
    if (output == eOutput::A)
    {
        *tccra = (*tccra & 0b00111111) | (compareMode << 6);
    }
    else
    {
        *tccra = (*tccra & 0b11001111) | (compareMode << 4);
    }
}

void TimerHw::selectWaveGenerationMode(eWaveGenerationMode waveGenMode)
{
    if (waveGenMode & 0b00000100)
    {
        *tccrb |= (1 << 3);
    }
    else
    {
        *tccrb &= ~(1 << 3);
    }
    *tccra = (*tccra & 0b11111100) | (waveGenMode & 0b00000011);
}

void TIMER0_COMPA_vect(void)
{
    TimerHw::vector_table[0]->handler();
}

void TIMER1_COMPA_vect(void)
{
    TimerHw::vector_table[1]->handler();
}

void TIMER2_COMPA_vect(void)
{
    TimerHw::vector_table[2]->handler();
}
