#ifndef PINCHANGEINT_H
#define PINCHANGEINT_H


class PinChangeInt : public iInterrupt
{
//variables
public:
    void (*pinChangeISR)(bool pinState) = nullptr;
protected:
private:

//functions
public:
    PinChangeInt(void (*pinChangeISR)(bool));
    ~PinChangeInt();
    void isr(const void *) override;
protected:
private:
};


#endif //PINCHANGEINT_H
