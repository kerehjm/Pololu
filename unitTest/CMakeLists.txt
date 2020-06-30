cmake_minimum_required(VERSION 3.5)

add_compile_options(
    -Wall
    -std=c++11)

include(cmake/config-gtest.cmake)
include(cmake/setup.cmake)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(example ${CMAKE_CURRENT_SOURCE_DIR}/src/example.cpp)
target_link_libraries(example gtest_main)
add_test(NAME example_test COMMAND example)
