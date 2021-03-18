/* 
* Timer_0.h
*
* Created: 15/05/2020 16:30:39
* Author: Mathew.Kuloba
*/


#ifndef __TIMER_H__
#define __TIMER_H__

template <class T>
class Timer : public iTimer<T>
{
//variables
public:
protected:
private:
    iTimerHw<T> * timerHw;

//functions
public:
    Timer<T>(iTimerHw<T> * timerHw);
    ~Timer();
    void start();
    void startInverted();
    void stop();
    void setFrequency(T frequency);
    void setDutyCycle(T dutyCycle);
    T getCount();
protected:
private:

}; //Timer

#endif //__TIMER_H__
