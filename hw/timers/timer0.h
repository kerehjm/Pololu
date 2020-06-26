/* 
* Timer_0.h
*
* Created: 15/05/2020 16:30:39
* Author: Mathew.Kuloba
*/


#ifndef __TIMER_0_H__
#define __TIMER_0_H__

#include "iTimer.h"

enum eClockSourceTimer0
{
    noClkSrcTimer0,
    noPreScalerTimer0,
    prescaler8Timer0,
    prescaler64Timer0,
    prescaler256Timer0,
    prescaler1024Timer0
};

class Timer0 : public iTimer
{
//variables
public:
protected:
private:
    static volatile uint8_t top;
    static volatile uint8_t reload;

//functions
public:
	Timer0();
	~Timer0();
    void start();
    void startInverted();
    void stop();
    void setTop(uint8_t top);
    void setReload(uint8_t reload);
    uint8_t getCount();
protected:
private:
    void selectClock(eClockSourceTimer0 clockSource);
    void selectCompareOutputMode(eOutput output, eoutputCompareMode compareMode);
    void selectWaveGenerationMode(eWaveGenerationMode waveGenMode);

}; //Timer_0

#endif //__TIMER_0_H__
