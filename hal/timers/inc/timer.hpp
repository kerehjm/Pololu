/* 
* Timer_0.h
*
* Created: 15/05/2020 16:30:39
* Author: Mathew.Kuloba
*/


#ifndef __TIMER_H__
#define __TIMER_H__

class Timer : public iTimer
{
//variables
public:
protected:
private:
    iTimerHw * timerHw;

//functions
public:
    Timer(iTimerHw * timerHw);
    ~Timer();
    void start();
    void stop();
    void setFrequency(uint16_t frequency);
    void setDutyCycle(uint16_t dutyCycle);
    uint16_t getCount();
protected:
private:

}; //Timer

#endif //__TIMER_H__
