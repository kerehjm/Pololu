add_library(hwLcd STATIC OBJECT
    src/hd44780.cpp
    src/hd44780Base.cpp
    src/hd44780Factory.cpp
)

target_compile_options(hwLcd PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(hwLcd PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(hwLcd PRIVATE inc)

target_link_libraries(hwLcd PRIVATE iHw)
