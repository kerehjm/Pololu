#include <avr/interrupt.h>
#include "iInterrupt.hpp"
#include "pinChangeInt.hpp"

static PinChangeInt pPinChangeInt(nullptr);

PinChangeInt::PinChangeInt(void (*pinChangeISR)(bool))
{
    if(nullptr == this->pinChangeISR)
    {
        this->pinChangeISR = pinChangeISR;
    }
};

PinChangeInt::~PinChangeInt()
{ 
};

void PinChangeInt::isr(const void * pinState) 
{
    pinChangeISR(pinState);
}

ISR(PCINT1_vect)
{
    bool pinState= false;
    pPinChangeInt.isr(&pinState); //TODO add pin state check
}