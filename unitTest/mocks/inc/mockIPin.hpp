#ifndef __MOCKIPIN_H__
#define __MOCKIPIN_H__

#include <gmock/gmock.h>
#include "iPin.hpp"

class mockIPin : public iPin
{
public:
    MOCK_METHOD0(set, void());
    MOCK_METHOD0(reset, void());
    MOCK_METHOD0(toggle, void());
    MOCK_METHOD0(output, void());
    MOCK_METHOD0(input, void());
    MOCK_METHOD0(is_pin_set, bool());
};

#endif //__MOCKIPIN_H__