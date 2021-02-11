/* 
* TimerHW.h
*
* Created: 15/05/2020 16:30:39
* Author: Mathew.Kuloba
*/


#ifndef __TIMER_HW_H__
#define __TIMER_HW_H__

extern "C" void TIMER0_COMPA_vect(void) __attribute__ ((signal));
extern "C" void TIMER1_COMPA_vect(void) __attribute__ ((signal));
extern "C" void TIMER2_COMPA_vect(void) __attribute__ ((signal));

class TimerHw : public iTimerHw
{
//variables
public:
protected:
private:
    volatile uint16_t * ocra;
    volatile uint16_t * ocrb;
    volatile uint16_t * tcnt;
    volatile uint8_t * tccra;
    volatile uint8_t * tccrb;
    ePrescaler prescaler;
    static TimerHw * vector_table[eInterruptId::max];
    void (*handler)(void);

//functions
public:
    TimerHw(volatile uint16_t *  ocra, volatile uint16_t * ocrb, volatile uint16_t * tcnt,
            volatile uint8_t * tccra, volatile uint8_t * tccrb, eoutputCompareMode AcompareMode,
            eoutputCompareMode BcompareMode, eWaveGenerationMode waveGenMode, ePrescaler prescaler, eInterruptId intId, void(*isr)(void));
    ~TimerHw();
    void start();
    void startInverted();
    void stop();
    void setTop(uint8_t top);
    void setReload(uint8_t reload);
    uint8_t getCount();
protected:
private:
    friend void TIMER0_COMPA_vect(void);
    friend void TIMER1_COMPA_vect(void);
    friend void TIMER2_COMPA_vect(void);
    void selectClock(ePrescaler clockSource);
    void selectCompareOutputMode(eOutput output, eoutputCompareMode compareMode);
    void selectWaveGenerationMode(eWaveGenerationMode waveGenMode);

}; //Timer_Hw

#endif //__TIMER_HW_H__
