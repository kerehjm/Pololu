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
#include "iButtonHw.hpp"
#include "iButton.hpp"
#include "button.hpp"

//TODO use a queue

// default constructor
Button::Button(eButtonId buttonId, iButtonHw * buttonHw)
{
    this->buttonId = buttonId;
    this->buttonHw = buttonHw;
} //Button

// default destructor
Button::~Button()
{
} //~Button

bool Button::isPressed()
{
    return buttonHw->isPressed();
}

bool Button::add(iObserver* observer)
{
    bool result = false;
    
    if(!observerExists(observer))
    {
        for (uint8_t i = 0; i < MAX_NO_OF_OBSERVERS; i++)
        {
            if(nullptr == observers[i]) //empty slot
            {
                observers[i] = observer; //add observer
                result = true;
                break;
            }
        }
    }
    return result;
}

void Button::remove(iObserver* observer)
{
    for (uint8_t i = 0; i < MAX_NO_OF_OBSERVERS; i++)
    {
        if(observer == observers[i]) //observer found
        {
            observers[i] = nullptr; //remove observer
            break;
        }
    }
}

void Button::notify()
{
    for (uint8_t i = 0; i < MAX_NO_OF_OBSERVERS; i++)
    {
        if(nullptr != observers[i]) //observer registered
        {
            observers[i]->update(isPressed());
        }
    }
}

bool Button::observerExists(iObserver* observer)
{
    bool result = false;
    for (uint8_t i = 0; i < MAX_NO_OF_OBSERVERS; i++)
    {
        if(observer == observers[i])
        {
            result = true;
            break;
        }
    }
    return result;
}
