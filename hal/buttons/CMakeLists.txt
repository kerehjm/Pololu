add_library(buttons STATIC
    button.cpp
    buttonA.cpp
    buttonB.cpp
    buttonC.cpp
    buttonFactory.cpp)

target_include_directories(buttons PRIVATE ../../hw/pins)
target_link_libraries(buttons PRIVATE pins)
