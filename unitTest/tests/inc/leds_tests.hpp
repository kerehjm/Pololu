#include <gtest/gtest.h>
#include <stdint.h>
#include "iLed.hpp"
#include "iPin.hpp"
#include "led.hpp"

#include "mockiPin.hpp"

using ::testing::AtLeast;

TEST(LedsTest, pinResetOnCreation) {
    MockiPin pin;

    EXPECT_CALL(pin, reset())
        .Times(1);

    Led led(&pin);
}

TEST(LedsTest, pinSetWhenTurnedOn) {
    MockiPin pin;

    EXPECT_CALL(pin, reset())
        .Times(1);
    EXPECT_CALL(pin, set())
        .Times(1);

    Led led(&pin);
    led.on();
}

TEST(LedsTest, pinResetWhenTurnedOff) {
    MockiPin pin;

    EXPECT_CALL(pin, reset())
        .Times(2);

    Led led(&pin);
    led.off();
}

TEST(LedsTest, pinTogglesWhenToggled) {
    MockiPin pin;

    EXPECT_CALL(pin, reset())
        .Times(1);
    EXPECT_CALL(pin, toggle())
        .Times(1);

    Led led(&pin);
    led.toggle();
}
