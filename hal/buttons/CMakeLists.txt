add_library(halButtons STATIC OBJECT
    src/button.cpp
)

target_compile_options(halButtons PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(halButtons PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(halButtons PUBLIC inc)

target_link_libraries(halButtons PRIVATE iHal)
target_link_libraries(halButtons PRIVATE iHw)
target_link_libraries(halButtons PRIVATE iUtils)
target_link_libraries(halButtons PRIVATE utilsObserver)
