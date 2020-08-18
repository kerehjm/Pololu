/* 
* Button.cpp
*
* Created: 17/05/2020 12:40:38
* Author: Mathew.Kuloba
*/
#include <stdint.h>
#include <string.h>
#include "iObserver.hpp"
#include "iSubject.hpp"
#include "subject.hpp"
#include "iPinHw.hpp"
#include "iInterrupt.hpp"
#include "iButton.hpp"
#include "button.hpp"

//TODO use a queue

// default constructor
Button::Button(iPinHw * buttonPinHw, iInterrupt* buttonInt)
{
    this->buttonPinHw = buttonPinHw;
    this->buttonInt = buttonInt;
} //Button

// default destructor
Button::~Button()
{
} //~Button

bool Button::isPressed()
{
    return !buttonPinHw->isSet();
}
