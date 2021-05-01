add_library(hwButton STATIC OBJECT
    src/buttonHw.cpp
    src/buttonHwFactory.cpp
)

target_compile_options(hwButton PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(hwButton PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(hwButton PRIVATE inc)

target_link_libraries(hwButton PRIVATE iHw)
