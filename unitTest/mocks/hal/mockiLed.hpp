#ifndef __MOCKILED_H__
#define __MOCKILED_H__

#include <gmock/gmock.h>
#include "iLed.hpp"

class MockiLed : public iLed 
{
public:
    MOCK_METHOD0(on, void());
    MOCK_METHOD0(off, void());
    MOCK_METHOD0(toggle, void());
};

#endif //__MOCKILED_H__
