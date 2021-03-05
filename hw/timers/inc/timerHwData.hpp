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
    TimerHwData(volatile T * ocra, volatile T * ocrb,
        volatile T * tcnt,
        volatile uint8_t * tccra, volatile uint8_t * tccrb, uint8_t * timsk)
    {
        this->ocra = ocra;
        this->ocrb = ocrb;
        this->tcnt = tcnt;
        this->tccra = tccra;
        this->tccrb = tccrb;
        this->timsk = timsk;

        *(this->ocra ) = 0;
        *(this->ocrb ) = 0;
        *(this->tcnt ) = 0;
        *(this->tccra) = 0;
        *(this->tccrb) = 0;
        *(this->timsk) = 0;

        this->ePrescaler = 0;
    };
protected:
    void setOcra(T ocra) { *(this->ocra ) = ocra; }
    void setOcrb(T ocra) { *(this->ocrb ) = ocrb; }
    void setTcnt(T tcnt) { *(this->tcnt ) = tcnt; }
    void setTccra(uint8_t tccra) { *(this->tccra ) = tccra; }
    void setTccrb(uint8_t tccrb) { *(this->tccrb ) = tccrb; }
    void setTimsk(uint8_t timsk) { *(this->timsk ) = timsk; }
    void setPrescaler(ePrescaler prescaler) { *(this->prescaler) = prescaler; }
    T getOcra() const { return *(this->ocra); }
    T getOcrb() const { return *(this->ocrb); } 
    T getTcnt() const { return *(this->tcnt); }
    uint8_t getTccra() const { return *(this->tccra); }
    uint8_t getTccrb() const { return *(this->tccrb); }
    uint8_t getTimsk() const { return *(this->timsk); }
    P getPrescaler() const { return *(this->prescaler); }
private:

};

#endif //TIMERHWDATA_H
