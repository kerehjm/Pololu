add_library(utilsObserver STATIC OBJECT
    src/subject.cpp
)

target_compile_options(utilsObserver PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(utilsObserver PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(utilsObserver PUBLIC inc)

target_link_libraries(utilsObserver PRIVATE iUtils)
