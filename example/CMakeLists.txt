add_library(example STATIC OBJECT
    src/whattotest.cpp
)

target_compile_options(example PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(example PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(example PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
