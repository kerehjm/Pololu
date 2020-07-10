#ifndef __MOCKITIMERHW_H__
#define __MOCKITIMERHW_H__

#include <gmock/gmock.h>
#include "iTimerHw.h"

class MockiTimerHw : public iTimerHw
{
public:
    MOCK_METHOD0(start, void());
    MOCK_METHOD0(startInverted, void());
    MOCK_METHOD0(stop, void());
    MOCK_METHOD1(setTop, void(uint8_t top));
    MOCK_METHOD1(setReload, void(uint8_t reload));
};

#endif //__MOCKITIMERHW_H__
