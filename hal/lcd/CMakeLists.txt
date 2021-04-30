add_library(halLcd STATIC OBJECT
    src/lcd.cpp
    src/lcdFactory.cpp
)

target_compile_options(halLcd PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(halLcd PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(halLcd PUBLIC inc)

target_link_libraries(halLcd PRIVATE iHal)
target_link_libraries(halLcd PRIVATE iHw)
