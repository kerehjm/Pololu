/* 
* iTimer.h
*
* Created: 17/05/2020 13:39:10
* Author: Mathew.Kuloba
*/


#ifndef __ITIMER_H__
#define __ITIMER_H__

enum class eTimerId
{
    counter,
    counter_2,
    pwm,
    pwm2
}; //eTimerId

template <class T>
class iTimer
{
//functions
public:
    virtual ~iTimer(){}
    static iTimer<uint16_t> * create(eTimerId timerId, void (*callback)(void)= nullptr);
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void setFrequency(T frequency) = 0;
    virtual void setDutyCycle(T dutyCycle) = 0;
    virtual T getCount() = 0;
}; //iTimer

#endif //__ITIMER_H__
