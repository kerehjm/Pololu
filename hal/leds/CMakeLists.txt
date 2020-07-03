add_library(leds STATIC OBJECT
    src/led.cpp
)

target_compile_options(leds PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(leds PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(leds PRIVATE inc)

target_link_libraries(leds PRIVATE iHal)
target_link_libraries(leds PRIVATE iHw)
