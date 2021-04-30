add_library(hwParallel4bit STATIC OBJECT
    src/parallel4bit.cpp
    src/parallel4bitFactory.cpp
)

target_compile_options(hwParallel4bit PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(hwParallel4bit PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(hwParallel4bit PRIVATE inc)

target_link_libraries(hwParallel4bit PRIVATE iHw)
