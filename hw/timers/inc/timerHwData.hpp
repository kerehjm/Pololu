#ifndef TIMERHWDATA_H
#define TIMERHWDATA_H

template<class T, class P>
class TimerHwData : public iTimerHwData<T, P>
{
//variables
public:
protected:
private:
    volatile T * ocra;
    volatile T * ocrb;
    volatile T * tcnt;
    volatile uint8_t * tccra;
    volatile uint8_t * tccrb;
    volatile uint8_t * timsk;
    P prescaler;

//functions
public:
    ~TimerHwData();
    TimerHwData(
        volatile T * ocra,
        volatile T * ocrb,
        volatile T * tcnt,
        volatile uint8_t * tccra,
        volatile uint8_t * tccrb,
        volatile uint8_t * timsk);
protected:
    void setOcra(T ocra);
    void setOcrb(T ocrb);
    void setTcnt(T tcnt);
    void setTccra(uint8_t tccra);
    void setTccrb(uint8_t tccrb);
    void setTimsk(uint8_t timsk);
    void setPrescaler(P prescaler);
    T getOcra();
    T getOcrb();
    T getTcnt();
    uint8_t getTccra();
    uint8_t getTccrb();
    uint8_t getTimsk();
    P getPrescaler();
private:

};

#endif //TIMERHWDATA_H
