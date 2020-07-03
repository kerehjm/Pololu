add_library(hwTimer STATIC OBJECT
    src/timer0.cpp
    src/timer1.cpp
    src/timer2.cpp
)

target_compile_options(hwTimer PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(hwTimer PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(hwTimer PRIVATE inc)

target_link_libraries(hwTimer PRIVATE iHw)
