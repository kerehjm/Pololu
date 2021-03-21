#ifndef ITIMERHWDATA_H
#define ITIMERHWDATA_H

enum class ePrescaler;
enum class ePrescaler_ext;

template<class T, class P>
class iTimerHwData
{
//functions
public:
    ~iTimerHwData() {}
    static iTimerHwData<uint8_t, ePrescaler_ext> * createTimer0();
    static iTimerHwData<uint16_t, ePrescaler_ext> * createTimer1();
    static iTimerHwData<uint8_t, ePrescaler> * createTimer2();
    virtual void setOcra(T ocra) = 0;
    virtual void setOcrb(T ocrb) = 0;
    virtual void setTcnt(T tcnt) = 0;
    virtual void setPrescaler(P prescaler) = 0;
    virtual T getOcra() = 0;
    virtual T getOcrb() = 0;
    virtual T getTcnt() = 0;
    virtual P getPrescaler(void) = 0;

    virtual void setTccra(uint8_t tccra) = 0;
    virtual void setTccrb(uint8_t tccrb) = 0;
    virtual void setTimsk(uint8_t timsk) = 0;

    virtual uint8_t getTccra() = 0;
    virtual uint8_t getTccrb() = 0;
    virtual uint8_t getTimsk() = 0;
};

#endif //ITIMERHWDATA_H