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

enum class eInterruptId
{
    timer0_compa,
    timer1_compa,
    timer2_compa,
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

enum class eWaveGenerationMode : unsigned
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

enum class  ePrescaler_ext
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

struct registers_t
{
    volatile uint8_t * ocra;
    volatile uint8_t * ocrb;
    volatile uint8_t * tcnt;
    volatile uint8_t * tccra;
    volatile uint8_t * tccrb;

    registers_t() {};

    registers_t(volatile uint8_t * ocra, volatile uint8_t * ocrb,
        volatile uint8_t * tcnt,
        volatile uint8_t * tccra, volatile uint8_t * tccrb)
    {
        this->ocra = ocra;
        this->ocrb = ocrb;
        this->tcnt = tcnt;
        this->tccra = tccra;
        this->tccrb = tccrb;
    }
};

class iTimerHw
{
//functions
public:
    static iTimerHw * createCounter_CTC(eTimerHwId hwTimerId, uint16_t frequency, void (*callback)(void));
    static iTimerHw * createCounter_FastPwm(eTimerHwId hwTimerId, uint16_t frequency, void (*callback)(void));
    static iTimerHw * createPwm(eTimerHwId hwTimerId, uint16_t frequency);
    static registers_t getRegisters(eTimerHwId hwTimerId);
    virtual ~iTimerHw(){}
    virtual void start() = 0;
    virtual void startInverted() = 0;
    virtual void stop() = 0;
    virtual void setTop(uint16_t top) = 0;
    virtual void setReload(uint16_t reload) = 0;
    virtual uint16_t getCount() = 0;

}; //iTimerHw

#endif //__ITIMERHW_H__
