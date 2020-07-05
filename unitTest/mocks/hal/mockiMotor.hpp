#ifndef __MOCKIMOTORH__
#define __MOCKIMOTORH__

#include <gmock/gmock.h>
#include "iMotor.hpp"

class MockiMotor : public iMotor
{
public:
    MOCK_METHOD0(off, void());
    MOCK_METHOD1(forward, void(uint8_t speed));
    MOCK_METHOD1(reverse, void(uint8_t speed));
    MOCK_METHOD0(brake, void());
};

#endif //__MOCKIMOTORH__