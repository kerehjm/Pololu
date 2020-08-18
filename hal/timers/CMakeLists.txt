add_library(halTimers STATIC OBJECT
    src/timer.cpp
)

target_compile_options(halTimers PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(halTimers PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(halTimers PRIVATE inc)

target_link_libraries(halTimers PRIVATE iHal)
target_link_libraries(halTimers PRIVATE iHw)
