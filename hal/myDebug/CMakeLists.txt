add_library(halMyDebug STATIC OBJECT
    src/myDebug.cpp
)

target_compile_options(halMyDebug PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(halMyDebug PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(halMyDebug PUBLIC inc)

target_link_libraries(halMyDebug PRIVATE iHal)
target_link_libraries(halMyDebug PRIVATE iHw)
