add_library(halPins STATIC OBJECT
    src/pin.cpp
    src/pinFactory.cpp
)

target_compile_options(halPins PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(halPins PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(halPins PUBLIC inc)

target_link_libraries(halPins PRIVATE iHal)
target_link_libraries(halPins PRIVATE iHw)
