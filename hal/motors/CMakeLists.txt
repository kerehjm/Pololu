add_library(motors STATIC OBJECT
    src/motor.cpp
    src/motorFactory
)

target_compile_options(motors PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(motors PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(motors PRIVATE inc)

target_link_libraries(motors PRIVATE iHal)
target_link_libraries(motors PRIVATE iHw)
