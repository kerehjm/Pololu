add_library(uart STATIC OBJECT
    src/uart.cpp
)

target_compile_options(uart PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(uart PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(uart PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_link_libraries(uart PUBLIC pins) #TODO why pins needs to be public
