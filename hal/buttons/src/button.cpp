/* 
* Button.cpp
*
* Created: 17/05/2020 12:40:38
* Author: Mathew.Kuloba
*/

#include "iButton.hpp"
#include "button.hpp"

// default constructor
Button::Button(eButtonId button)
{
    this->button = button;
} //Button

// default destructor
Button::~Button()
{
} //~Button

bool Button::isPressed()
{
    return false;
}
