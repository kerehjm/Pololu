add_library(hwTimer STATIC OBJECT
    src/timerHw.cpp
    src/timerHwDataFactory.cpp
    src/timerHwFactory.cpp
)

target_compile_options(hwTimer PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(hwTimer PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(hwTimer PRIVATE inc)

target_link_libraries(hwTimer PRIVATE iHw)

# add_library(hwTimer INTERFACE)

# target_include_directories(hwTimer INTERFACE inc)
# target_include_directories(hwTimer INTERFACE src)

# target_link_libraries(hwTimer INTERFACE iHw)
