add_library(motors STATIC
    motor.cpp)

target_include_directories(motors PRIVATE ../../hw/pins ../../hw/timers ../myDebug)
target_link_libraries(motors PRIVATE pins myDebug timers)
