add_library(pins STATIC OBJECT
    src/pinFactory.cpp
    src/pin.cpp
    src/pinPortMap.cpp)

target_include_directories(pins PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
