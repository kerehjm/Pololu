add_library(motors STATIC
    src/motor.cpp
    src/motorFactory.cpp)

target_include_directories(motors PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_link_libraries(motors PRIVATE pins myDebug timers)
