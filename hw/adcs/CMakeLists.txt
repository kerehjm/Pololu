add_library(hwAdc STATIC OBJECT
    src/adc.cpp
)

target_compile_options(hwAdc PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(hwAdc PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(hwAdc PRIVATE inc)

target_link_libraries(hwAdc PRIVATE iHw)
