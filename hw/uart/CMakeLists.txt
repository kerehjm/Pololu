add_library(HwUart STATIC OBJECT
    src/uart.cpp
)

target_compile_options(HwUart PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(HwUart PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(HwUart PRIVATE inc)

target_link_libraries(HwUart PRIVATE iHw)
