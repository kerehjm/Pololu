add_library(leds STATIC
    led.cpp
    ledFactory.cpp)

target_include_directories(leds PRIVATE ../../hw/pins)
target_link_libraries(leds PRIVATE pins)
