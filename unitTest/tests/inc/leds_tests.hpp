#include <gtest/gtest.h>
#include "iLed.hpp"
#include "iPinHw.hpp"
#include "led.hpp"

#include "mockiPinHw.hpp"

using ::testing::AtLeast; 

TEST(LedsTest, pinResetOnCreation) {
    MockiPinHw pinHw;

    EXPECT_CALL(pinHw, reset())
        .Times(AtLeast(1));

    Led led(&pinHw);
}

TEST(LedsTest, pinSetWhenTurnedOn) {
    MockiPinHw pinHw;

    Led led(&pinHw);

    EXPECT_CALL(pinHw, set())
        .Times(AtLeast(1));

    led.on();
}

TEST(LedsTest, pinResetWhenTurnedOff) {
    MockiPinHw pinHw;

    Led led(&pinHw);

    EXPECT_CALL(pinHw, reset())
        .Times(AtLeast(1));

    led.off();
}

TEST(LedsTest, pinTogglesWhenToggled) {
    MockiPinHw pinHw;

    Led led(&pinHw);

    EXPECT_CALL(pinHw, toggle())
        .Times(AtLeast(1));

    led.toggle();
}
