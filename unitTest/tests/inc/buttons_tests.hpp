#include <stdint.h>
#include "iObserver.hpp"
#include "iSubject.hpp"
#include "iButtonHw.hpp"
#include "iButton.hpp"
#include "button.hpp"
#include <gtest/gtest.h>

#include "mockiButtonHw.hpp"
#include "mockiObserver.hpp"

TEST(ButtonsTest, isPressedCallsButtonHwIsPressed) {
    MockiButtonHw buttonHw;

    EXPECT_CALL(buttonHw, isPressed())
        .Times(1);

    Button button(eButtonId::a, &buttonHw);

    ASSERT_FALSE(button.isPressed());
}

TEST(ButtonsTest, addObserverIsSuccessfull) {
    MockiButtonHw buttonHw;
    MockiObserver observer;

    Button button(eButtonId::a, &buttonHw);

    ASSERT_TRUE(button.add(&observer));
}

TEST(ButtonsTest, addingAnExistingObserverFails) {
    MockiButtonHw buttonHw;
    MockiObserver observer;

    Button button(eButtonId::a, &buttonHw);

    button.add(&observer);
    ASSERT_FALSE(button.add(&observer));
}

TEST(ButtonsTest, addMoreThanOneObserverIsSuccessfull) {
    MockiButtonHw buttonHw;
    MockiObserver observer1;
    MockiObserver observer2;
    MockiObserver observer3;
    MockiObserver observer4;

    Button button(eButtonId::a, &buttonHw);

    button.add(&observer1);
    button.add(&observer2);
    button.add(&observer3);
    ASSERT_TRUE(button.add(&observer4));
}

TEST(ButtonsTest, addMoreThanMaxObserversFails) {
    MockiButtonHw buttonHw;
    MockiObserver observer1;
    MockiObserver observer2;
    MockiObserver observer3;
    MockiObserver observer4;
    MockiObserver observer5;
    MockiObserver observer6;
    MockiObserver observer7;
    MockiObserver observer8;
    MockiObserver observer9;
    MockiObserver observer10;
    MockiObserver observer11;

    Button button(eButtonId::a, &buttonHw);

    button.add(&observer1);
    button.add(&observer2);
    button.add(&observer3);
    button.add(&observer4);
    button.add(&observer5);
    button.add(&observer6);
    button.add(&observer7);
    button.add(&observer8);
    button.add(&observer9);
    button.add(&observer10);
    ASSERT_FALSE(button.add(&observer11));
}

TEST(ButtonsTest, removeIsSuccessfull) {
    MockiButtonHw buttonHw;
    MockiObserver observer;

    Button button(eButtonId::a, &buttonHw);

    button.add(&observer);
    button.remove(&observer);
    ASSERT_TRUE(button.add(&observer));
}

TEST(ButtonsTest, notifyOnlyNotifiesSubscribedObservers) {
    MockiButtonHw buttonHw;
    MockiObserver observer1;
    MockiObserver observer2;
    MockiObserver observer3;
    MockiObserver observer4;

    EXPECT_CALL(observer1, update(false))
        .Times(1);
    EXPECT_CALL(observer2, update(false))
        .Times(1);
    EXPECT_CALL(observer3, update(false))
        .Times(1);
    EXPECT_CALL(observer4, update(false))
        .Times(0);

    Button button(eButtonId::a, &buttonHw);

    button.add(&observer1);
    button.add(&observer2);
    button.add(&observer3);

    button.notify();
}

TEST(ButtonsTest, notifyDoesntNotifyRemovedObservers) {
    MockiButtonHw buttonHw;
    MockiObserver observer1;
    MockiObserver observer2;
    MockiObserver observer3;
    MockiObserver observer4;

    EXPECT_CALL(observer1, update(false))
        .Times(1);
    EXPECT_CALL(observer2, update(false))
        .Times(1);
    EXPECT_CALL(observer3, update(false))
        .Times(1);
    EXPECT_CALL(observer4, update(false))
        .Times(0);

    Button button(eButtonId::a, &buttonHw);

    button.add(&observer1);
    button.add(&observer2);
    button.add(&observer3);
    button.add(&observer4);

    button.remove(&observer4);

    button.notify();
}