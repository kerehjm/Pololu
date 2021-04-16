cmake_minimum_required(VERSION 3.5)

#device dependent config, here for arduino uno on linux
set(AVR_MCU atmega328p)
set(MCU_FREQ 20000000UL)
set(AVR_PROGRAMMER stk500)
set(AVR_PROGRAMMER_PORT /dev/tty.usbmodem000700031)
set(AVR_PROGRAMMER_BAUDRATE 115200)
set(PROGRAM_EEPROM False)

#set build options
set(AVR_RELEASE_BUILD_FLAGS
    -Os
    -Wall
    -Werror
    -std=c++11
    -mmcu=${AVR_MCU}
    -DF_CPU=${MCU_FREQ} 
)

set(AVR_DEBUG_BUILD_FLAGS
    -g
    -Wpedantic #Issue all the warnings demanded by strict ISO C and ISO C++
    -Wall
    -Wextra
    -W
    -O1
    -Werror
    -std=c++11
    -mmcu=${AVR_MCU}
    -DF_CPU=${MCU_FREQ} 
)

set(AVR_RELEASE_LINK_FLAGS
    -W
    -mrelax
    --data-sections
    -mmcu=${AVR_MCU}
)

set(AVR_DEBUG_LINK_FLAGS
    -W
    -mrelax
    --data-sections
    -mmcu=${AVR_MCU}
)

include(cmake/avr.cmake)

project(pololu CXX)

# call after project setup
include(cmake/setup.cmake)

avr_add_executable(3pi app/main.cpp)

target_link_libraries(3pi.elf PRIVATE
    hw
    hal
)

add_subdirectory(hw)
add_subdirectory(hal)
