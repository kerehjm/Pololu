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

struct registers_t
{
    volatile uint16_t * ocra;
    volatile uint16_t * ocrb;
    volatile uint16_t * tcnt;
    volatile uint8_t * tccra;
    volatile uint8_t * tccrb;
};

class TimerHw : public iTimerHw
{
//variables
public:
protected:
private:
    registers_t registers;
    volatile uint16_t top;
    volatile uint16_t reload;
    ePrescaler prescaler;
    static TimerHw * vector_table[eInterruptId::max];
    void (*handler)(void);

//functions
public:
    TimerHw(registers_t &registers, eoutputCompareMode AcompareMode,
            eoutputCompareMode BcompareMode, eWaveGenerationMode waveGenMode, ePrescaler prescaler, eInterruptId intId, uint16_t frequency, void(*isr)(void));
    ~TimerHw();
    void start();
    void startInverted();   
    void stop();
    void setTop(uint16_t top);
    void setReload(uint16_t reload);
    uint16_t getCount();
protected:
private:
    friend void TIMER0_COMPA_vect(void);
    friend void TIMER1_COMPA_vect(void);
    friend void TIMER2_COMPA_vect(void);
    void selectClock(ePrescaler clockSource);
    void selectCompareOutputMode(eOutput output, eoutputCompareMode compareMode);
    void selectWaveGenerationMode(eWaveGenerationMode waveGenMode);
    void intHandler(eInterruptId intId);

}; //Timer_Hw

#endif //__TIMER_HW_H__
