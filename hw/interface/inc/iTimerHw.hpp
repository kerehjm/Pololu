/* 
* iTimerHw.h
*
* Created: 17/05/2020 13:39:10
* Author: Mathew.Kuloba
*/


#ifndef __ITIMERHW_H__
#define __ITIMERHW_H__

typedef void (*fPointer_t)();

enum class eTimerId
{
    tmr0,
    tmr1,
    tmr2
}; //eTimerId

enum eInterrupts
{
    overflow,
    outputCompareMatchA,
    outputCompareMatchB
};

enum eOutput
{
    A,
    B
};

enum eoutputCompareMode
{
    normalCompare,
    toggleOnCompare,
    clearClearOnCompare,
    setOnCompare
};

enum eWaveGenerationMode
{
    normalGeneration,
    pwmPhaseCorrect,
    ctc,
    fastPwm,
    pwmPhaseCorrect2 = 5,
    fastPwm2 = 7
};

class iTimerHw
{
//functions
public:
    virtual ~iTimerHw(){}
    virtual void start() = 0;
    virtual void startInverted() = 0;
    virtual void stop() = 0;
    virtual void setTop(uint8_t top) = 0;
    virtual void setReload(uint8_t reload) = 0;
    virtual uint8_t getCount() = 0;

}; //iTimerHw

#endif //__ITIMERHW_H__
