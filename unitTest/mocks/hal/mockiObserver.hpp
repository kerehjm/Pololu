#ifndef __MOCKIOBSERVERH__
#define __MOCKIOBSERVERH__

#include <gmock/gmock.h>
#include "iObserver.hpp"

class MockiObserver : public iObserver
{
public:
    MOCK_METHOD1(update, void(bool isPressed));
};

#endif //__MOCKIOBSERVERH__
