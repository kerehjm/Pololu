#include <gtest/gtest.h>
#include "iPin.hpp"
#include "iPinHw.hpp"
#include "pin.hpp"

#include "mockiPinHw.hpp"

using ::testing::AtLeast; 

TEST(PinTests, pinSetOutputOnCreation) {
    MockiPinHw pinHw;

    EXPECT_CALL(pinHw, set())
        .Times(AtLeast(1));
    EXPECT_CALL(pinHw, output())
        .Times(AtLeast(1));

    Pin pin(ePinId::PB0_LCD_RW, &pinHw, ePinDir::OUTPUT, ePinState::HIGH);
}

TEST(PinTests, pinResetInputOnCreation) {
    MockiPinHw pinHw;

    EXPECT_CALL(pinHw, reset())
        .Times(AtLeast(1));
    EXPECT_CALL(pinHw, input())
        .Times(AtLeast(1));

    Pin pin(ePinId::PB0_LCD_RW, &pinHw, ePinDir::INPUT, ePinState::LOW);
}

TEST(PinTests, pinSetSetsPinHw) {
    MockiPinHw pinHw;

    EXPECT_CALL(pinHw, reset())
        .Times(AtLeast(1));
    EXPECT_CALL(pinHw, input())
        .Times(AtLeast(1));

    EXPECT_CALL(pinHw, set())
        .Times(AtLeast(1));

    Pin pin(ePinId::PB0_LCD_RW, &pinHw, ePinDir::INPUT, ePinState::LOW);

    pin.set();
}

TEST(PinTests, pinResetResetsPinHw) {
    MockiPinHw pinHw;

    EXPECT_CALL(pinHw, reset())
        .Times(AtLeast(2));
    EXPECT_CALL(pinHw, input())
        .Times(AtLeast(1));

    Pin pin(ePinId::PB0_LCD_RW, &pinHw, ePinDir::INPUT, ePinState::LOW);

    pin.reset();
}

TEST(PinTests, pinToggleTogglesPinHw) {
    MockiPinHw pinHw;

    EXPECT_CALL(pinHw, reset())
        .Times(AtLeast(1));
    EXPECT_CALL(pinHw, input())
        .Times(AtLeast(1));

    EXPECT_CALL(pinHw, toggle())
        .Times(AtLeast(1));

    Pin pin(ePinId::PB0_LCD_RW, &pinHw, ePinDir::INPUT, ePinState::LOW);

    pin.toggle();
}

TEST(PinTests, pinInputCallsPinHwInput) {
    MockiPinHw pinHw;

    EXPECT_CALL(pinHw, reset())
        .Times(AtLeast(1));
    EXPECT_CALL(pinHw, input())
        .Times(AtLeast(2));

    Pin pin(ePinId::PB0_LCD_RW, &pinHw, ePinDir::INPUT, ePinState::LOW);

    pin.input();
}

TEST(PinTests, pinOutputCallsPinHwOutput) {
    MockiPinHw pinHw;

    EXPECT_CALL(pinHw, reset())
        .Times(AtLeast(1));
    EXPECT_CALL(pinHw, input())
        .Times(AtLeast(1));

    EXPECT_CALL(pinHw, output())
        .Times(AtLeast(1));

    Pin pin(ePinId::PB0_LCD_RW, &pinHw, ePinDir::INPUT, ePinState::LOW);

    pin.output();
}

TEST(PinTests, pinIsSetCallsPinHwIsSetAndIsReset) {
    MockiPinHw pinHw;

    EXPECT_CALL(pinHw, reset())
        .Times(AtLeast(1));
    EXPECT_CALL(pinHw, input())
        .Times(AtLeast(1));

    EXPECT_CALL(pinHw, isSet())
        .Times(AtLeast(1));

    Pin pin(ePinId::PB0_LCD_RW, &pinHw, ePinDir::INPUT, ePinState::LOW);

    bool actual = pin.isSet();

    ASSERT_EQ(actual, 0);
}

