add_library(myDebug STATIC OBJECT
    src/myDebug.cpp
)

target_compile_options(myDebug PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(myDebug PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(myDebug PUBLIC inc)

target_link_libraries(myDebug PRIVATE iHal)
target_link_libraries(myDebug PRIVATE iHw)
