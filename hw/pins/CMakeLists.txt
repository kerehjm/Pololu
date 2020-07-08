add_library(hwPin STATIC OBJECT
    src/pinHw.cpp
    src/pinPortMap.cpp
    src/hwPinFactory.cpp
)

target_compile_options(hwPin PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(hwPin PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(hwPin PRIVATE inc)

target_link_libraries(hwPin PRIVATE iHw)
