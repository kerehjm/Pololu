#ifndef __MOCKIBUTTONHW_H__
#define __MOCKIBUTTONHW_H__

#include <gmock/gmock.h>
#include "iButtonHw.hpp"

class MockiButtonHw : public iButtonHw
{
public:
    MOCK_METHOD0(isPressed, bool());
};

#endif //__MOCKIBUTTONHW_H__
