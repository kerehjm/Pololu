/* 
* Timer1.h
*
* Created: 16/05/2020 00:08:16
* Author: Mathew.Kuloba
*/


#ifndef __TIMER1_H__
#define __TIMER1_H__

#include "iTimer.h"

extern "C" void TIMER1_COMPA_vect(void) __attribute__ ((signal));

class Timer1 : public iTimer
{
//variables
public:
    static fPointer_t timerCallback; //TODO make private
protected:
private:

//functions
public:
	Timer1(fPointer_t timerCallback);
	~Timer1();
    void start();
    void startInverted();
    void stop();
    void setTop(uint8_t top);
    void setReload(uint8_t reload);
    uint8_t getCount();
protected:
private:
    friend void TIMER1_COMPA_vect(void);
	Timer1( const Timer1 &c );
	Timer1& operator=( const Timer1 &c );

}; //Timer1

#endif //__TIMER1_H__
