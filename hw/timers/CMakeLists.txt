add_library(timers STATIC OBJECT
    src/timer0.cpp
    src/timer1.cpp
    src/timer2.cpp
    src/timerFactory.cpp
)

target_compile_options(timers PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(timers PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")
    
target_include_directories(timers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
