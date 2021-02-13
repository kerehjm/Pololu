#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "iTimerHw.hpp"
#include "timerHw.hpp"

TimerHw * TimerHw::vector_table[eInterruptId::max] = {nullptr};

// default constructor
TimerHw::TimerHw(registers_t &registers,
                 eoutputCompareMode AcompareMode, eoutputCompareMode BcompareMode,
                 eWaveGenerationMode waveGenMode, ePrescaler prescaler,
                 eInterruptId intId, uint16_t frequency, void(*isr)(void))
{
    this->top = frequency;
    this->reload = 0;

    this->registers.ocra = registers.ocra;
    this->registers.ocrb = registers.ocrb;
    this->registers.tccra = registers.tccra;
    this->registers.tccrb = registers.tccrb;
    this->registers.tcnt = registers.tcnt;

    *this->registers.ocra = frequency;
    *this->registers.ocrb = 0;
    *this->registers.tccra = 0;
    *this->registers.tccrb = 0;
    *this->registers.tcnt = 0;
    this->prescaler = prescaler;

    selectCompareOutputMode(eOutput::A, AcompareMode);
    selectCompareOutputMode(eOutput::B, BcompareMode);
    selectWaveGenerationMode(waveGenMode);

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

void TimerHw::setTop(uint16_t top)
{
    TimerHw::top = top;
}
void TimerHw::setReload(uint16_t reload)
{
    TimerHw::reload = reload;
}

uint16_t TimerHw::getCount()
{
    return *registers.tcnt;
}

//Private function

void TimerHw::selectClock(ePrescaler clockSource)
{
    *registers.tccrb = (*registers.tccrb & 0b11111000) | clockSource;
}

void TimerHw::selectCompareOutputMode(eOutput output, eoutputCompareMode compareMode)
{
    if (output == eOutput::A)
    {
        *registers.tccra = (*registers.tccra & 0b00111111) | (compareMode << 6);
    }
    else
    {
        *registers.tccra = (*registers.tccra & 0b11001111) | (compareMode << 4);
    }
}

void TimerHw::selectWaveGenerationMode(eWaveGenerationMode waveGenMode)
{
    *registers.tccra = (*registers.tccra & 0b11111100) | (waveGenMode & 0b00000011);
    *registers.tccrb = (*registers.tccrb & 0b11100111) | ((waveGenMode << 1) & 0b00011000);
}

void TimerHw::intHandler(eInterruptId intId)
{
    if (intId == eInterruptId::timer1_compa)
    {
        if (handler != nullptr)
        {
            handler();
        }
    }
    // *registers.ocra = TimerHw::top;
    // *registers.ocrb = TimerHw::reload;
}

void TIMER0_COMPA_vect(void)
{
    TimerHw::vector_table[0]->intHandler(timer0_compa);
}

void TIMER1_COMPA_vect(void)
{
    TimerHw::vector_table[1]->intHandler(timer1_compa);
}

void TIMER2_COMPA_vect(void)
{
    TimerHw::vector_table[2]->intHandler(timer2_compa);
}
