/* 
* TimerFactory.cpp
*
* Created: 18/05/2020 18:43:36
* Author: Mathew.Kuloba
*/


#include "timerFactory.h"

iTimer *TimerFactory::create(eTimerId timer_id, fPointer_t timerCallback)
{
    iTimer *timer = nullptr;
    switch (timer_id)
    {
        case eTimerId::tmr0:
        timer = new Timer0();
        break;
        case eTimerId::tmr1:
        timer = new Timer1(timerCallback);
        break;
        case eTimerId::tmr2:
        timer = new Timer2();
        break;
    }
    return timer;
}
