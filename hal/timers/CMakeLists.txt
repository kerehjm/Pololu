add_library(timers STATIC OBJECT
    src/timer.cpp
)

target_compile_options(timers PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(timers PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(timers PRIVATE inc)

target_link_libraries(timers PRIVATE iHal)
target_link_libraries(timers PRIVATE iHw)
