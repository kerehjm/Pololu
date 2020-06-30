add_library(pins STATIC OBJECT
    src/pinFactory.cpp
    src/pin.cpp
    src/pinPortMap.cpp
)

target_compile_options(pins PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(pins PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(pins PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
