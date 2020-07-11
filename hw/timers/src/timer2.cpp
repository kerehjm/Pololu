/* 
* Timer_2.cpp
*
* Created: 15/05/2020 16:40:10
* Author: Mathew.Kuloba
*/

#include <stdint.h>
#include <avr/io.h>
#include "iTimerHw.hpp"
#include "timer2.hpp"
//#include "myDebug.hpp"

// default constructor
Timer2::Timer2()
{
    selectCompareOutputMode(eOutput::A, clearClearOnCompare);
    selectCompareOutputMode(eOutput::B, clearClearOnCompare);
    selectWaveGenerationMode(eWaveGenerationMode::pwmPhaseCorrect);
    
    OCR2A = OCR2B = 0;
    
    start();
    //Debug::write(eDebugLevel::info, "Timer2 created");
} //Timer_2

// default destructor
Timer2::~Timer2()
{
   //Debug::write(eDebugLevel::info, "Timer2 destroyed");
} //~Timer_2

void Timer2::start()
{
    selectClock(eClockSourceTimer2::prescaler8Timer2);
    //Debug::write(eDebugLevel::info, "Timer2 start");
}

void Timer2::startInverted()
{
    //Debug::write(eDebugLevel::info, "Timer2 start inverted");
}

void Timer2::stop()
{
    selectClock(eClockSourceTimer2::noClkSrcTimer2);
    
    //Debug::write(eDebugLevel::info, "Timer2 stop");
}

void Timer2::setTop(uint8_t top)
{
    OCR2A = top;
}
void Timer2::setReload(uint8_t reload)
{
    OCR2B = reload;
}

uint8_t Timer2::getCount()
{
    return TCNT2;
}

//Private function

void Timer2::selectClock(eClockSourceTimer2 clockSource)
{
    TCCR2B = (TCCR2B & 0b11111000) | clockSource;
}

void Timer2::selectCompareOutputMode(eOutput output, eoutputCompareMode compareMode)
{
    if (output == eOutput::A)
    {
        TCCR2A = (TCCR2A & 0b00111111) | (compareMode << 6);
    }
    else
    {
        TCCR2A = (TCCR2A & 0b11001111) | (compareMode << 4);
    }
}

void Timer2::selectWaveGenerationMode(eWaveGenerationMode waveGenMode)
{
    if (waveGenMode & 0b00000100)
    {
        TCCR2B |= (1 << 3);
    }
    else
    {
        TCCR2B &= ~(1 << 3);
    }
    TCCR2A = (TCCR2A & 0b11111100) | (waveGenMode & 0b00000011);
}
