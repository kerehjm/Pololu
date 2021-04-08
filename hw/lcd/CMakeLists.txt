add_library(hwLcd STATIC OBJECT
    src/lcdHw.cpp
    src/lcdHwFactory.cpp
)

target_compile_options(hwLcd PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(hwLcd PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(hwLcd PRIVATE inc)

target_link_libraries(hwLcd PRIVATE iHw)
