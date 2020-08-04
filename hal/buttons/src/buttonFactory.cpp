//
// Created by Mathew Kere on 08/07/2020.
//

#include <stdint.h>
#include "iButtonHw.hpp"
#include "iButton.hpp"
#include "button.hpp"

iButton * iButton::create(eButtonId buttonId) 
{
    iButton * button = nullptr;
    iButtonHw * buttonHw = nullptr;

#ifndef GOOGLE_TEST // unit tests dont like static functions called in a static functions because they cant be mocked
    switch (buttonId)
    {
        case eButtonId::a             : buttonHw = iButtonHw::create( eHwButtonId::a          ); break;
        case eButtonId::b             : buttonHw = iButtonHw::create( eHwButtonId::b          ); break;
        case eButtonId::c             : buttonHw = iButtonHw::create( eHwButtonId::c          ); break;
    }
#endif
    button = new Button(buttonId, buttonHw);
    return button;
}
