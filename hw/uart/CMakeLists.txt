add_library(hwUart STATIC OBJECT
    src/uart.cpp
    src/uartFactory.cpp
)

target_compile_options(hwUart PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(hwUart PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(hwUart PRIVATE inc)

target_link_libraries(hwUart PRIVATE iHw)
