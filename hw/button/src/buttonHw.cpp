#include <stdint.h>
#include <avr/io.h>
#include "iPinHw.hpp"
#include "iButtonHw.hpp"
#include "buttonHw.hpp"

ButtonHw * ButtonHw::vector_table[static_cast<uint8_t>(eButtonIntId::max)] = {nullptr};

ButtonHw::ButtonHw(iPinHw * buttonPin, eButtonIntId intId, volatile uint8_t * pcicr, volatile uint8_t * pcmsk, void(*callback)(void))
{
    this->pcicr = pcicr;
    this->pcmsk = pcmsk;

    ButtonHw::vector_table[static_cast<uint8_t>(intId)] = this;
    this->callback = callback;
    this->buttonPin = buttonPin;

    *(this->pcicr) |= static_cast<uint8_t>(ePcie::pcie0);
    *(this->pcmsk) |= static_cast<uint8_t>(ePcmsk::_1 | ePcmsk::_4 | ePcmsk::_5);
}

ButtonHw::~ButtonHw(void)
{
    delete(pcicr);
    delete(pcmsk);
    callback = nullptr;
}

bool ButtonHw::is_pressed(void)
{
    return buttonPin->isSet();
}

void ButtonHw::intHandler(eButtonIntId intId)
{
    if (callback != nullptr)
    {
        if ((intId == eButtonIntId::pcint0) && (buttonPin->isSet() == false))
        {
            callback();
        }
    }
}

//PCINT7-0 PCMSK0
void PCINT0_vect(void)
{
    ButtonHw::vector_table[static_cast<uint8_t>(eButtonIntId::pcint0)]->intHandler(eButtonIntId::pcint0);
}

//PCINT14-8 PCMSK1
void PCINT1_vect(void)
{
    ButtonHw::vector_table[static_cast<uint8_t>(eButtonIntId::pcint1)]->intHandler(eButtonIntId::pcint1);
}

//PCINT23-16 PCMSK2
void PCINT2_vect(void)
{
    ButtonHw::vector_table[static_cast<uint8_t>(eButtonIntId::pcint2)]->intHandler(eButtonIntId::pcint2);
}
