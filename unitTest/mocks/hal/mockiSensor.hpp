#ifndef __MOCKISENSORH__
#define __MOCKISENSORH__

#include <gmock/gmock.h>
#include "iSensor.hpp"

class MockiSensor : public iSensor
{
public:
    MOCK_METHOD0(read, uint8_t());
    MOCK_METHOD0(charge, void());
    MOCK_METHOD0(discharge, void());
};

#endif //__MOCKISENSORH__