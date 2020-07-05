#ifndef __MOCKIBUTTON_H__
#define __MOCKIBUTTON_H__

#include <gmock/gmock.h>
#include "iButton.hpp"

class MockiButton : public iButton 
{
public:
    MOCK_METHOD0(isPressed, bool());
};

#endif //__MOCKIBUTTON_H__