add_library(buttons STATIC
    src/button.cpp
    src/buttonA.cpp
    src/buttonB.cpp
    src/buttonC.cpp
    src/buttonFactory.cpp)

target_include_directories(buttons PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_link_libraries(buttons PRIVATE pins)
