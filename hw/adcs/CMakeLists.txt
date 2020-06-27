add_library(adcs STATIC
    src/adc.cpp)

target_include_directories(adcs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
