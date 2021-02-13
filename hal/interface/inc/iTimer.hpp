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
    pwm
}; //eTimerId

class iTimer
{
//functions
public:
    virtual ~iTimer(){}
    static iTimer * create(eTimerId timerId, void (*callback)(void));
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void reload(uint16_t count) = 0;
    virtual uint16_t getCount() = 0;
}; //iTimer

#endif //__ITIMER_H__
