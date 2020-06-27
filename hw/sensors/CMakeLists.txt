add_library(sensors STATIC
    proximitySensor.cpp
    reflectanceSensor.cpp
    sensorFactory.cpp
    sensor.cpp)

target_include_directories(sensors PRIVATE ../pins)
target_include_directories(sensors PRIVATE ../timers)
target_link_libraries(sensors PRIVATE pins)
target_link_libraries(sensors PRIVATE timers)