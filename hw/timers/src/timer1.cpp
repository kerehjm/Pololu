/* 
* Timer1.cpp
*
* Created: 16/05/2020 00:08:16
* Author: Mathew.Kuloba
*/

#include <stdint.h>
#include <avr/io.h>
#include "iTimerHw.hpp"
#include "timer1.hpp"
//#include "myDebug.h"

fPointer_t Timer1::timerCallback = nullptr;

// default constructor
Timer1::Timer1(fPointer_t timerCallback)
{
    Timer1::timerCallback = timerCallback;
    //Wave generation mode - CTC mode
    TCCR1B |= (1 << WGM12);

    //Initialize compare registers to TOP
    OCR1A = 0x4C4B; //Set compare value for 1 sec overflow
    
    //Debug::write(eDebugLevel::info, "Timer1 init");
} //Timer1

// default destructor
Timer1::~Timer1()
{
    
} //~Timer1

//Interrupt Service Routine for TIMER1 COMPA
// ISR(TIMER1_COMPA_vect)
// {
//     Timer1::timerCallback();
// }

uint8_t Timer1::getCount()
{
    return TCNT1;
}

void Timer1::start()
{
    //Enable interrupts
    TIMSK1 |= ( 1 << OCIE1A ); //Timer1 COMPA int enable
    
    //Clock select - Internal pre-scaler 1024
    TCCR1B |= ( 1 << CS10 )|( 1 << CS12 ); //Start the timer Internal pre-scaler 1024
    
    //Debug::write(eDebugLevel::info, "Timer1 enable");
}

void Timer1::startInverted()
{
    
}

void Timer1::stop()
{
    
}

void Timer1::setTop(uint8_t top)
{
    
}
void Timer1::setReload(uint8_t reload)
{
    
}
