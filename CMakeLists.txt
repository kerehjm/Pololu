cmake_minimum_required(VERSION 3.5)
project(pololu)

#device dependent config, here for arduino uno on linux
set(AVR_MCU atmega328p)
set(MCU_FREQ 20000000UL)
set(AVR_PROGRAMMER stk500)
set(AVR_PROGRAMMER_PORT /dev/ttyACM0)
#set(AVR_PROGRAMMER_BAUDRATE 19200)
set(PROGRAM_EEPROM False)

include(cmake/avr.cmake)

add_compile_options(
    -Wall
    -std=c++11 
    -mmcu=atmega328p)

avr_add_executable(3pi 
    app/main.cpp)

add_subdirectory(hw/pins)
add_subdirectory(hw/adcs)
add_subdirectory(hw/timers)
add_subdirectory(hw/sensors)
add_subdirectory(hw/uart)
add_subdirectory(hal/myDebug)
add_subdirectory(hal/motors)
add_subdirectory(hal/leds)
add_subdirectory(hal/buttons)

#private dependancies
target_link_libraries(3pi.elf PRIVATE
    pins
    adcs
    timers
    sensors
    uart
    myDebug
    leds
    motors
    buttons
    )