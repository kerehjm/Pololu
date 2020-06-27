cmake_minimum_required(VERSION 3.5)
project(pololu)

add_compile_options(
    -Wall
    -std=c++11 
    -mmcu=atmega328p)

add_executable(3pi 
    app/main.cpp)

find_program(AVR_CXX avr-g++) #todo not needed

add_subdirectory(hw/pins)
add_subdirectory(hw/adcs)
add_subdirectory(hw/timers)
add_subdirectory(hw/sensors)
add_subdirectory(hw/uart)
add_subdirectory(hal/buttons)
add_subdirectory(hal/leds)
add_subdirectory(hal/myDebug)
add_subdirectory(hal/motors)

target_include_directories(3pi PRIVATE
    hw/pins
    hw/adcs
    hw/timers
    hw/sensors
    hw/uart
    hal/buttons
    hal/myDebug
    hal/leds
    hal/motors
    )

#private dependancies
target_link_libraries(3pi PRIVATE
    pins
    adcs
    timers
    sensors
    uart
    buttons
    )