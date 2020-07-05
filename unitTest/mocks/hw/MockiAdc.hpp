#ifndef __MOCKIADC_H__
#define __MOCKIADC_H__

#include <gmock/gmock.h>
#include "iAdc.hpp"

enum eAdcId
{
    adcChannel0,
    adcChannel1,
    adcChannel2,
    adcChannel3,
    adcChannel4,
    adcChannel5,
    adcChannel6,
    adcChannel7,
    adcChanneltemp
}; //eAdcId

class MockiAdc : public iAdc
{
public:
    MOCK_METHOD0(init, void());
    MOCK_METHOD0(on, void());
    MOCK_METHOD0(off, void());
    MOCK_METHOD1(read, uint8_t(eAdcId channel));
};

#endif //__MOCKIADC_H__