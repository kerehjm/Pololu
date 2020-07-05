#include <gtest/gtest.h>
#include "iLed.hpp"
#include "iPin.hpp"
#include "led.hpp"

#include "mockIPin.hpp"
using ::testing::AtLeast; 

TEST(LedsTest, pinResetOnCreation) {
    mockIPin pin;

    EXPECT_CALL(pin, reset())
        .Times(AtLeast(1));

    Led led(&pin);
}

TEST(LedsTest, pinSetWhenTurnedOn) {
    mockIPin pin;

    EXPECT_CALL(pin, reset())
        .Times(AtLeast(1));

    Led led(&pin);

    EXPECT_CALL(pin, set())
        .Times(AtLeast(1));

    led.on();
}
