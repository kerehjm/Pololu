#include "iButtonHw.hpp"
#include "iButton.hpp"
#include "button.hpp"

iButton * iButton::create(eButtonId buttonId, void (*callback)(void))
{
    iButtonHw * buttonHw = nullptr;
    switch (buttonId)
    {
    case eButtonId::a:
        buttonHw = iButtonHw::create(eButtonHwId::pb1, callback);
        break;
    case eButtonId::b:
        buttonHw = iButtonHw::create(eButtonHwId::pb4, callback);
        break;
    case eButtonId::c:
        buttonHw = iButtonHw::create(eButtonHwId::pb5, callback);
        break;
    
    default:
        break;
    }

    iButton * button = new Button(buttonHw);

    return button;
}