add_library(halMotors STATIC OBJECT
    src/motor.cpp
)

target_compile_options(halMotors PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(halMotors PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(halMotors PRIVATE inc)

target_link_libraries(halMotors PRIVATE iHal)
target_link_libraries(halMotors PRIVATE iHw)
