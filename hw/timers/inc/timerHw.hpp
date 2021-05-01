/* 
* TimerHW.h
*
* Created: 15/05/2020 16:30:39
* Author: Mathew.Kuloba
*/


#ifndef TIMER_HW_H
#define TIMER_HW_H

extern "C" void TIMER0_COMPA_vect(void) __attribute__ ((signal));
extern "C" void TIMER1_COMPA_vect(void) __attribute__ ((signal));
extern "C" void TIMER2_COMPA_vect(void) __attribute__ ((signal));

template<class T, class P, class W>
class TimerHw : public iTimerHw<T>
{
//variables
public:
protected:
private:
    iTimerHwData<T, P> * registers;
    static TimerHw * vector_table[static_cast<uint8_t>(eInterruptId::max)];
    void (*handler)(void);
    eInterruptId intId;

//functions
public:
    TimerHw<T, P, W>(
        iTimerHwData<T, P> * registers,
        eoutputCompareMode AcompareMode,
        eoutputCompareMode BcompareMode,
        W waveGenMode,
        P prescaler,
        eInterruptId intId,
        T frequency,
        void(*isr)(void) = nullptr);
    ~TimerHw();
    void start();
    void startInverted();   
    void stop();
    void setTop(T top);
    void setReload(T reload);
    T getCount();
    void selectCompareOutputMode(eOutput output, eoutputCompareMode compareMode);
protected:
private:
    friend void TIMER0_COMPA_vect(void);
    friend void TIMER1_COMPA_vect(void);
    friend void TIMER2_COMPA_vect(void);
    friend void TIMER0_COMPB_vect(void);
    friend void TIMER1_COMPB_vect(void);
    friend void TIMER2_COMPB_vect(void);
    void selectClock(P clockSource);
    void selectWaveGenerationMode(W waveGenMode);
    void intHandler(eInterruptId intId);

}; //Timer_Hw

#endif //TIMER_HW_H
