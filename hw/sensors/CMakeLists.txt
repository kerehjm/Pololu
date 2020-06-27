add_library(sensors STATIC OBJECT
    src/proximitySensor.cpp
    src/reflectanceSensor.cpp
    src/sensorFactory.cpp
    src/sensor.cpp)

target_include_directories(sensors PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_link_libraries(sensors PRIVATE pins)
target_link_libraries(sensors PRIVATE timers)