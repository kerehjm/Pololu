/* 
* Timer_2.h
*
* Created: 15/05/2020 16:40:10
* Author: Mathew.Kuloba
*/


#ifndef __TIMER_2_H__
#define __TIMER_2_H__

#include <avr/io.h>
#include "iTimer.hpp"

enum eClockSourceTimer2
{
    noClkSrcTimer2,
    noPreScalerTimer2,
    prescaler8Timer2,
    prescaler32Timer2,
    prescaler64Timer2,
    prescaler128Timer2,
    prescaler256Timer2,
    prescaler1024Timer2
};

class Timer2 : public iTimer
{
//variables
public:
protected:
private:

//functions
public:
	Timer2();
	~Timer2();
    void start();
    void startInverted();
    void stop();
    void setTop(uint8_t top);
    void setReload(uint8_t reload);
    uint8_t getCount();
protected:
private:
    void selectClock(eClockSourceTimer2 clockSource);
    void selectCompareOutputMode(eOutput output, eoutputCompareMode compareMode);
    void selectWaveGenerationMode(eWaveGenerationMode waveGenMode);
}; //Timer_2

#endif //__TIMER_2_H__
