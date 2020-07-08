add_library(pins STATIC OBJECT
    src/pin.cpp
    src/pinFactory
)

target_compile_options(pins PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(pins PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(pins PRIVATE inc)

target_link_libraries(pins PRIVATE iHal)
target_link_libraries(pins PRIVATE iHw)
