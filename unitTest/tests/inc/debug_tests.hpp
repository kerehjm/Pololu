#include <gtest/gtest.h>
#include "iUart.hpp"
#include "iDebug.hpp"
#include "myDebug.hpp"

#include "mockiUart.hpp"

using ::testing::AtLeast;

TEST(MyDebugTests, debugUartEnabledOnCreation) {
    MockiUart uart;

    EXPECT_CALL(uart, enable())
        .Times(1);

    Debug _debug(&uart, eDebugLevel::Error);
}

TEST(MyDebugTests, debugNotPrintedWhenLevelIsSetBelowGlobalLevel) {
    MockiUart uart;

    EXPECT_CALL(uart, write('\n'))
        .Times(0);
    EXPECT_CALL(uart, write('H'))
        .Times(0);

    Debug _debug(&uart, eDebugLevel::Error);

    _debug.log(eDebugLevel::info, "HHHHH");
}

TEST(MyDebugTests, debugPrintedWhenLevelIsSetAboveGlobalLevel) {
    MockiUart uart;

    EXPECT_CALL(uart, write('\n'))
        .Times(1);
    EXPECT_CALL(uart, write('H'))
        .Times(5);

    Debug _debug(&uart, eDebugLevel::info);

    _debug.log(eDebugLevel::Error, "HHHHH");
}
