#ifndef __MOCKIUART_H__
#define __MOCKIUART_H__

#include <gmock/gmock.h>
#include "iUart.hpp"

class MockiUart : public iUart
{
public:
    MOCK_METHOD0(enable, void());
    MOCK_METHOD0(disable, void());
    MOCK_METHOD1(write, void(uint8_t data));
};

#endif //__MOCKIUART_H__
