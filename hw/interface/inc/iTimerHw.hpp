/* 
* iTimerHw.h
*
* Created: 17/05/2020 13:39:10
* Author: Mathew.Kuloba
*/


#ifndef __ITIMERHW_H__
#define __ITIMERHW_H__

enum class eTimerHwId
{
    tmr0,
    tmr1,
    tmr2
}; //eTimerId

enum class eInterruptId
{
    timer0_compa,
    timer1_compa,
    timer2_compa,
    timer0_compb,
    timer1_compb,
    timer2_compb,
    max
}; //eInterruptId

enum class eInterrupts
{
    overflow,
    outputCompareMatchA,
    outputCompareMatchB
};

enum class eOutput
{
    A,
    B
};

enum class  eoutputCompareMode
{
    normalCompare,
    toggleOnCompare,
    clearClearOnCompare,
    setOnCompare 
};

enum class eWaveGenerationMode
{
    normalGeneration,
    ctc = 4,
    pwmPhaseFrequencyCorrect = 9,
    pwmPhaseCorrect = 11,
    fastPwm = 15
};

enum class eWaveGenerationMode_Tmr0
{
    normalGeneration,
    pwmPhaseCorrect,
    ctc = 2,
    fastPwm = 3,
};

enum class ePrescaler_ext
{
    noClkSrc,
    noPreScaler,
    prescaler8,
    prescaler64,
    prescaler256,
    prescaler1024
};

enum class ePrescaler
{
    noClkSrc,
    noPreScaler,
    prescaler8,
    prescaler32,
    prescaler64,
    prescaler128,
    
    prescaler256,
    prescaler1024
};

template<class T>
class iTimerHw
{
//functions
public:
    static iTimerHw<T> * createCounter_CTC(eTimerHwId hwTimerId, T frequency, void (*callback)(void));
    static iTimerHw<T> * createCounter_FastPwm(eTimerHwId hwTimerId, T frequency, void (*callback)(void));
    static iTimerHw<T> * createPwm(eTimerHwId hwTimerId, T frequency);
    virtual ~iTimerHw(){}
    virtual void start() = 0;
    virtual void startInverted() = 0;
    virtual void stop() = 0;
    virtual void setTop(T top) = 0;
    virtual void setReload(T reload) = 0;
    virtual void getCount(T &count) = 0;

}; //iTimerHw

#endif //__ITIMERHW_H__
