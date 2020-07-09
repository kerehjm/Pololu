#ifndef __MOCKIPINHW_H__
#define __MOCKIPINHW_H__

#include <gmock/gmock.h>
#include "iPinHw.hpp"

class MockiPinHw : public iPinHw
{
public:
    MOCK_METHOD1(create, iPinHw*(eHwPinId hwPinId));
    MOCK_METHOD0(set, void());
    MOCK_METHOD0(reset, void());
    MOCK_METHOD0(toggle, void());
    MOCK_METHOD0(output, void());
    MOCK_METHOD0(input, void());
    MOCK_METHOD0(isSet, bool());
};

#endif //__MOCKIPINHW_H__
