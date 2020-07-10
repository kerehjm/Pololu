#ifndef __MOCKITIMER_H__
#define __MOCKITIMER_H__

#include <gmock/gmock.h>
#include "iTimer.hpp"

class MockiTimer : public iTimer 
{
public:
    MOCK_METHOD1(start, void(uint8_t count));
    MOCK_METHOD0(stop, void());
    MOCK_METHOD1(reload, void(uint8_t count));
    MOCK_METHOD0(getCount, uint8_t());
};

#endif //__MOCKITIMER_H__
