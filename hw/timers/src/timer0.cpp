/* 
* Timer_0.cpp
*
* Created: 15/05/2020 16:30:39
* Author: Mathew.Kuloba
*/

#include <stdint.h>
#include <avr/io.h>
#include "iTimerHw.hpp"
#include "timer0.hpp"
//#include "myDebug.h"

volatile uint8_t Timer0::top = 0;
volatile uint8_t Timer0::reload = 0;

// default constructor
Timer0::Timer0()
{
    selectCompareOutputMode(eOutput::A, clearClearOnCompare);
    selectCompareOutputMode(eOutput::B, clearClearOnCompare);
    selectWaveGenerationMode(eWaveGenerationMode::pwmPhaseCorrect);
    OCR0A = OCR0B = 0;
    start();
    //Debug::write(eDebugLevel::info, "Timer0 created");
} //Timer_0

// default destructor
Timer0::~Timer0()
{
    //Debug::write(eDebugLevel::info, "Timer0 destroyed");
} //~Timer_0

void Timer0::start()
{
    selectClock(eClockSourceTimer0::prescaler8Timer0);
    //Debug::write(eDebugLevel::info, "Timer0 start");
}

void Timer0::startInverted()
{
    //Debug::write(eDebugLevel::info, "Timer0 start inverted");
}

void Timer0::stop()
{
    selectClock(eClockSourceTimer0::noClkSrcTimer0);
    
    //Debug::write(eDebugLevel::info, "Timer0 stop");
}

void Timer0::setTop(uint8_t top)
{
    OCR0A = top;
}
void Timer0::setReload(uint8_t reload)
{
    OCR0B = reload;
}

uint8_t Timer0::getCount()
{
    return TCNT0;
}

//Private function

void Timer0::selectClock(eClockSourceTimer0 clockSource)
{
    TCCR0B = (TCCR0B & 0b11111000) | clockSource;
}

void Timer0::selectCompareOutputMode(eOutput output, eoutputCompareMode compareMode)
{
    if (output == eOutput::A)
    {
        TCCR0A = (TCCR0A & 0b00111111) | (compareMode << 6);
    }
    else
    {
        TCCR0A = (TCCR0A & 0b11001111) | (compareMode << 4);
    }
}

void Timer0::selectWaveGenerationMode(eWaveGenerationMode waveGenMode)
{
    if (waveGenMode & 0b00000100)
    {
        TCCR0B |= (1 << 3);
    }
    else
    {
        TCCR0B &= ~(1 << 3);
    }
    TCCR0A = (TCCR0A & 0b11111100) | (waveGenMode & 0b00000011);
}
