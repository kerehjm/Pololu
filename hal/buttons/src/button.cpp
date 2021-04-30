#include "iButtonHw.hpp"
#include "iButton.hpp"
#include "button.hpp"

// default constructor
Button::Button(iButtonHw * buttonHw)
{
    this->buttonHw = buttonHw;
}

// default destructor
Button::~Button()
{
    delete(buttonHw);
}

bool Button::isPressed()
{
    return buttonHw->is_pressed();
}
