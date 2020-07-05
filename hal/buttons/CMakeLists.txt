add_library(buttons STATIC OBJECT
    src/button.cpp
)

target_compile_options(buttons PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(buttons PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(buttons PUBLIC inc)

target_link_libraries(buttons PRIVATE iHal)
# target_link_libraries(buttons PRIVATE iHw)
