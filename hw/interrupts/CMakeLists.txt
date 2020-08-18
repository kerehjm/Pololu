add_library(hwInterrupts STATIC OBJECT
    src/pinChangeInt.cpp
)

target_compile_options(hwInterrupts PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(hwInterrupts PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(hwInterrupts PRIVATE inc)

target_link_libraries(hwInterrupts PRIVATE iHw)
