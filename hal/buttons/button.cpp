/* 
* Button.cpp
*
* Created: 17/05/2020 12:40:38
* Author: Mathew.Kuloba
*/


#include "button.h"

// default constructor
Button::Button()
{
} //Button

// default destructor
Button::~Button()
{
} //~Button

bool Button::isPressed()
{
    return pin->is_pin_set();
}