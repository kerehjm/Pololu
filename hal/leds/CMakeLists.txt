add_library(leds STATIC
    src/led.cpp
    src/ledFactory.cpp)

target_include_directories(leds PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_link_libraries(leds PRIVATE pins)
