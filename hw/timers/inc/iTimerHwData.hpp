#ifndef ITIMERHWDATA_H
#define ITIMERHWDATA_H

template<class T, class P>
class iTimerHwData
{
//functions
public:
    ~iTimerHwData() {}
    static iTimerHwData<T, P> * create(eTimerHwId hwTimerId);
    virtual void setOcra(T ocra) = 0;
    virtual void setOcrb(T ocrb) = 0;
    virtual void setTcnt(T tcnt) = 0;
    virtual void setPrescaler(P prescaler) = 0;
    virtual T getOcra(T& occra) = 0;
    virtual T getOcrb(T& occrb) = 0;
    virtual T getTcnt(T& tcnt) = 0;
    virtual P getPrescaler(void) = 0;

    virtual void setTccra(T tccra) = 0;
    virtual void setTccrb(T tccrb) = 0;
    virtual void setTimsk(T timsk) = 0;

    virtual T getTccra() = 0;
    virtual T getTccrb() = 0;
    virtual T getTimsk() = 0;
};

#endif //ITIMERHWDATA_H