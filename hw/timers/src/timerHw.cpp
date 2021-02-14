#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "iTimerHw.hpp"
#include "timerHw.hpp"

TimerHw * TimerHw::vector_table[(uint8_t)eInterruptId::max] = {nullptr};

// default constructor
TimerHw::TimerHw(registers_t &registers,
                 eoutputCompareMode AcompareMode, eoutputCompareMode BcompareMode,
                 eWaveGenerationMode waveGenMode, ePrescaler prescaler,
                 eInterruptId intId, uint16_t frequency, void(*isr)(void))
{
    this->top = frequency;
    this->reload = frequency;

    this->registers.ocra = registers.ocra;
    this->registers.ocrb = registers.ocrb;
    this->registers.tccra = registers.tccra;
    this->registers.tccrb = registers.tccrb;
    this->registers.tcnt = registers.tcnt;

    *this->registers.ocra = this->top;
    *this->registers.ocrb = this->reload;
    *this->registers.tccra = 0;
    *this->registers.tccrb = 0;
    *this->registers.tcnt = 0;

    selectCompareOutputMode(eOutput::A, AcompareMode);
    selectCompareOutputMode(eOutput::B, BcompareMode);
    selectWaveGenerationMode(waveGenMode);

    selectClock(prescaler);
 
    // TimerHw::vector_table[(uint8_t)intId] = this;
    // this->handler = isr;
    // TIMSK1 |= (1 << OCIE1A); // Enable CTC interrupt
    // sei(); //  Enable global interrupts
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
    *registers.tccrb = (*registers.tccrb & 0b11111000) | ((uint8_t)clockSource);
}

void TimerHw::selectCompareOutputMode(eOutput output, eoutputCompareMode compareMode)
{
    if (output == eOutput::A)
    {
        *registers.tccra = (*registers.tccra & 0b00111111) | (((uint8_t)compareMode) << 6);
    }
    else
    {
        *registers.tccra = (*registers.tccra & 0b11001111) | (((uint8_t)compareMode) << 4);
    }
}

void TimerHw::selectWaveGenerationMode(eWaveGenerationMode waveGenMode)
{
    *registers.tccra = (*registers.tccra & 0b11111100) | (((uint8_t)(waveGenMode)) & 0b00000011);
    *registers.tccrb = (*registers.tccrb & 0b11100111) | ((((uint8_t)(waveGenMode)) << 1) & 0b00011000);
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
    if (*registers.ocra != TimerHw::top)
    {
        *registers.ocra = TimerHw::top;
    }
    if (*registers.ocrb != TimerHw::reload)
    {
        *registers.ocrb = TimerHw::reload;
    }
}

void TIMER0_COMPA_vect(void)
{
    TimerHw::vector_table[0]->intHandler(eInterruptId::timer0_compa);
}

void TIMER1_COMPA_vect(void)
{
    TimerHw::vector_table[1]->intHandler(eInterruptId::timer1_compa);
}

void TIMER2_COMPA_vect(void)
{
    TimerHw::vector_table[2]->intHandler(eInterruptId::timer2_compa);
}
