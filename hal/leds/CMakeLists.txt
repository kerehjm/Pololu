add_library(halLeds STATIC OBJECT
    src/led.cpp
    src/ledFactory.cpp
)

target_compile_options(halLeds PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(halLeds PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(halLeds PUBLIC inc)

target_link_libraries(halLeds PRIVATE iHal)
target_link_libraries(halLeds PRIVATE iHw)
