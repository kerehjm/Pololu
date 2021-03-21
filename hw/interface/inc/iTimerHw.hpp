/* 
* iTimerHw.h
*
* Created: 17/05/2020 13:39:10
* Author: Mathew.Kuloba
*/


#ifndef __ITIMERHW_H__
#define __ITIMERHW_H__

enum class eTimerHwIdU8
{
    tmr0,
    tmr2
}; //eTimerHwIdU8

enum class eTimerHwIdU16
{
    tmr1,
}; //eTimerHwIdU16

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
    static iTimerHw<uint8_t> * createCounter_CTC(eTimerHwIdU8 hwTimerId, uint8_t frequency, void (*callback)(void));
    static iTimerHw<uint16_t> * createCounter_CTC(eTimerHwIdU16 hwTimerId, uint16_t frequency, void (*callback)(void));
    static iTimerHw<uint8_t> * createCounter_FastPwm(eTimerHwIdU8 hwTimerId, uint8_t frequency, void (*callback)(void));
    static iTimerHw<uint16_t> * createCounter_FastPwm(eTimerHwIdU16 hwTimerId, uint16_t frequency, void (*callback)(void));
    static iTimerHw<uint8_t> * createPwm(eTimerHwIdU8 hwTimerId, uint8_t frequency);
    static iTimerHw<uint16_t> * createPwm(eTimerHwIdU16 hwTimerId, uint16_t frequency);
    virtual ~iTimerHw(){}
    virtual void start() = 0;
    virtual void startInverted() = 0;
    virtual void stop() = 0;
    virtual void setTop(T top) = 0;
    virtual void setReload(T reload) = 0;
    virtual T getCount() = 0;
    virtual void selectCompareOutputMode(eOutput output, eoutputCompareMode compareMode) = 0;
}; //iTimerHw

#endif //__ITIMERHW_H__
