add_library(pwm STATIC OBJECT
    src/pwm.cpp
    src/pwmFactory.cpp
)

target_compile_options(pwm PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(pwm PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(pwm PRIVATE inc)

target_link_libraries(pwm PRIVATE iHal)
target_link_libraries(pwm PRIVATE iHw)
