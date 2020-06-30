add_library(adcs STATIC OBJECT
    src/adc.cpp
)

target_compile_options(adcs PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(adcs PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(adcs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
