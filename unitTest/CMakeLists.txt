cmake_minimum_required(VERSION 3.5)

project(pololu_test CXX)

set(TEST_BUILD_FLAGS
    -O0
    -Wall
    -Werror
    -std=c++11
)

include(cmake/config-gtest.cmake)
include(cmake/setup.cmake)

add_executable(runTest
    app/tests.cpp
)

target_compile_options(runTest PRIVATE ${TEST_BUILD_FLAGS})
target_include_directories(runTest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/tests)
target_link_libraries(runTest PUBLIC gtest_main)

#add source subirectories
add_subdirectory(../example ${CMAKE_CURRENT_BINARY_DIR}/test_build)

#link to source libraries
target_link_libraries(runTest PRIVATE example)

add_test(NAME tests COMMAND runTest)

