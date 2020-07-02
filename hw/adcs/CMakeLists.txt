add_library(HwAdc STATIC OBJECT
    src/adc.cpp
)

target_compile_options(HwAdc PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(HwAdc PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(HwAdc PRIVATE inc)

target_link_libraries(HwAdc PRIVATE iHw)
