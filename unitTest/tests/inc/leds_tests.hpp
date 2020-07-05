#include <gtest/gtest.h>
#include "iLed.hpp"
#include "iPin.hpp"
#include "led.hpp"

#include "mockiPin.hpp"

using ::testing::AtLeast; 

TEST(LedsTest, pinResetOnCreation) {
    MockiPin pin;

    EXPECT_CALL(pin, reset())
        .Times(AtLeast(1));

    Led led(&pin);
}

TEST(LedsTest, pinSetWhenTurnedOn) {
    MockiPin pin;

    Led led(&pin);

    EXPECT_CALL(pin, set())
        .Times(AtLeast(1));

    led.on();
}
