#ifndef __MOCKIPINHW_H__
#define __MOCKIPINHW_H__

#include <gmock/gmock.h>
#include "iPinHw.hpp"

class mockIPinHw : public iPinHw
{
public:
    MOCK_METHOD1(init, void(eHwPinId pinId));
    MOCK_METHOD1(set, void(eHwPinId pinId));
    MOCK_METHOD1(reset, void(eHwPinId pinId));
    MOCK_METHOD1(toggle, void(eHwPinId pinId));
    MOCK_METHOD1(output, void(eHwPinId pinId));
    MOCK_METHOD1(input, void(eHwPinId pinId));
    MOCK_METHOD1(is_pin_set, bool(eHwPinId pinId));
};

#endif //__MOCKIPINHW_H__