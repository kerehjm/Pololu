/* 
* ButtonFactory.cpp
*
* Created: 15/05/2020 22:27:53
* Author: Mathew.Kuloba
*/


#include "buttonFactory.h"

// functions
iButton *ButtonFactory::create(eButtonId button_id)
{
    iButton *button = nullptr;
    switch (button_id)
    {
        case eButtonId::a:
        button = new ButtonA();
        break;
        case eButtonId::b:
        button = new ButtonB();
        break;
        case eButtonId::c:
        button = new ButtonC();
        break;
    }
    return button;
}
