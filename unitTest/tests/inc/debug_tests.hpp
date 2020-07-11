#include <gtest/gtest.h>
// #include <stdint.h>
#include "iUart.hpp"
#include "iDebug.hpp"
#include "myDebug.hpp"

#include "mockiUart.hpp"

using ::testing::AtLeast;

TEST(MyDebugTests, debugEnabledOnCreation) {
    MockiUart uart;

    EXPECT_CALL(uart, enable())
        .Times(1);

    Debug _debug(&uart);
}
