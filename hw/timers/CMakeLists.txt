add_library(Hwtimer STATIC OBJECT
    src/timer0.cpp
    src/timer1.cpp
    src/timer2.cpp
)

target_compile_options(Hwtimer PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(Hwtimer PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(Hwtimer PRIVATE inc)

target_link_libraries(Hwtimer PRIVATE iHw)
