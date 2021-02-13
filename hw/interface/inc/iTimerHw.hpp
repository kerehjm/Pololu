/* 
* iTimerHw.h
*
* Created: 17/05/2020 13:39:10
* Author: Mathew.Kuloba
*/


#ifndef __ITIMERHW_H__
#define __ITIMERHW_H__

typedef void (*fPointer_t)();

enum class eTimerHwId
{
    tmr0,
    tmr1,
    tmr2
}; //eTimerId

enum eInterruptId
{
    timer0_compa,
    timer1_compa,
    timer2_compa,
    max
}; //eInterruptId

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
    ctc = 4,
    pwmPhaseFrequencyCorrect = 9,
    pwmPhaseCorrect = 11,
    fastPwm = 15
};

enum ePrescaler
{
    noClkSrc,
    noPreScaler,
    prescaler8,
    prescaler64,
    prescaler256,
    prescaler1024
};

class iTimerHw
{
//functions
public:
    static iTimerHw * createCounter(eTimerHwId hwTimerId, uint16_t frequency, void (*callback)(void));;
    static iTimerHw * createPwm(eTimerHwId hwTimerId, void (*callback)(void));
    virtual ~iTimerHw(){}
    virtual void start() = 0;
    virtual void startInverted() = 0;
    virtual void stop() = 0;
    virtual void setTop(uint16_t top) = 0;
    virtual void setReload(uint16_t reload) = 0;
    virtual uint16_t getCount() = 0;

}; //iTimerHw

#endif //__ITIMERHW_H__
