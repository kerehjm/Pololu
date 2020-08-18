cmake_minimum_required(VERSION 3.5)

#device dependent config, here for arduino uno on linux
set(AVR_MCU atmega328p)
set(MCU_FREQ 20000000UL)
set(AVR_PROGRAMMER stk500)
set(AVR_PROGRAMMER_PORT /dev/ttyACM0)
#set(AVR_PROGRAMMER_BAUDRATE 19200)
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
    iHal
    hwAdc
    hwButton
    hwInterrupts
    hwPin
    hwTimer
    hwUart
    halButtons
    halLeds
    halMotors
    halMyDebug
    halPins
    halSensors
    halTimers
    utilsObserver
)

add_subdirectory(hw/interface)
add_subdirectory(hw/adcs)
add_subdirectory(hw/pins)
add_subdirectory(hw/timers)
add_subdirectory(hw/uart)
add_subdirectory(hw/interrupts)
add_subdirectory(hw/buttons)

add_subdirectory(hal/buttons)
add_subdirectory(hal/interface)
add_subdirectory(hal/leds)
add_subdirectory(hal/motors)
add_subdirectory(hal/myDebug)
add_subdirectory(hal/pins)
add_subdirectory(hal/sensors)
add_subdirectory(hal/timers)

add_subdirectory(utils/interface)
add_subdirectory(utils/subject)
