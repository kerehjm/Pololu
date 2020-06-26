/* 
* TimerFactory.h
*
* Created: 18/05/2020 18:43:36
* Author: Mathew.Kuloba
*/


#ifndef __TIMERFACTORY_H__
#define __TIMERFACTORY_H__

#include "iTimer.h"
#include "eTimerId.h"
#include "timer0.h"
#include "timer1.h"
#include "timer2.h"

class TimerFactory
{
//variables
public:
protected:
private:

//functions
public:
    static iTimer *create(eTimerId timer_id, fPointer_t timerCallback);
protected:
private:
	TimerFactory();
	~TimerFactory();

}; //TimerFactory

#endif //__TIMERFACTORY_H__
