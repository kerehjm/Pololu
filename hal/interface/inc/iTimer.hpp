/* 
* iTimer.h
*
* Created: 17/05/2020 13:39:10
* Author: Mathew.Kuloba
*/


#ifndef __ITIMER_H__
#define __ITIMER_H__

enum class eTimerIdU8
{
    counter_1,
    counter_2,
}; //eTimerIdU8

enum class ePwmId
{
    pwm_1,
    pwm_2,
}; //ePwmId

template <class T>
class iTimer
{
//functions
public:
    virtual ~iTimer(){}
    static iTimer<uint16_t> * create(void (*callback)(void)= nullptr);
    static iTimer<uint8_t> * createU8(eTimerIdU8 timerId, void (*callback)(void)= nullptr);
    static iTimer<uint8_t> * createPwm(ePwmId pwmId);
    virtual void start() = 0;
    virtual void startInverted() = 0;
    virtual void stop() = 0;
    virtual void setFrequency(T frequency) = 0;
    virtual void setDutyCycle(T dutyCycle) = 0;
    virtual T getCount() = 0;
}; //iTimer

#endif //__ITIMER_H__
