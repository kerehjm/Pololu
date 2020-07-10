cmake_minimum_required(VERSION 3.5)

project(pololu_test CXX)

set(TEST_BUILD_FLAGS
    -g
    -O0
    -Wall
    -Werror
    -std=c++14
    -DGOOGLE_TEST
)

include(cmake/config-gtest.cmake)
include(cmake/setup.cmake)

add_executable(runTest
    app/main.cpp
)

add_definitions(-DGOOGLE_TEST) #path for static functions

# target_compile_options(runTest PRIVATE ${TEST_BUILD_FLAGS})
add_compile_options(${TEST_BUILD_FLAGS}) #use this to override libraries build flags
target_link_libraries(runTest PRIVATE #link to source libraries
    gtest_main
    gmock_main
    gtest
    tests
    mocks
    iHal
    iHw
    buttons
    leds
    pins
)

#add source subirectories
add_subdirectory(mocks)
add_subdirectory(tests)

add_subdirectory(../hal/interface ${CMAKE_CURRENT_BINARY_DIR}/cmake-build-ihal)
add_subdirectory(../hw/interface ${CMAKE_CURRENT_BINARY_DIR}/cmake-build-ihw)
add_subdirectory(../hal/buttons ${CMAKE_CURRENT_BINARY_DIR}/cmake-build-buttons)
add_subdirectory(../hal/leds ${CMAKE_CURRENT_BINARY_DIR}/cmake-build-leds)
add_subdirectory(../hal/motors ${CMAKE_CURRENT_BINARY_DIR}/cmake-build-motors)
add_subdirectory(../hal/myDebug ${CMAKE_CURRENT_BINARY_DIR}/cmake-build-myDebug)
add_subdirectory(../hal/pins ${CMAKE_CURRENT_BINARY_DIR}/cmake-build-pins)
add_subdirectory(../hal/sensors ${CMAKE_CURRENT_BINARY_DIR}/cmake-build-sensors)
add_subdirectory(../hal/timers ${CMAKE_CURRENT_BINARY_DIR}/cmake-build-timers)

add_test(NAME tests COMMAND runTest)

