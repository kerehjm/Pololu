#include "iButton.hpp"
#include "button.hpp"
#include <gtest/gtest.h>

TEST(ButtonsTest, isPressed) {
    Button button(eButtonId::a);
    ASSERT_TRUE(button.isPressed());
}
