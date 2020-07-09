#ifndef __MOCKIDEBUG_H__
#define __MOCKIDEBUG_H__

#include <gmock/gmock.h>
#include "iDebug.hpp"

class MockiDebug : public iDebug 
{
public:
    //MOCK_METHOD2(write, void(eDebugLevel level, const char *format, ...));
    MOCK_METHOD1(setLevel, void(eDebugLevel level));
};

#endif //__MOCKIDEBUG_H__
