add_library(sensors STATIC OBJECT
    src/proximitySensor.cpp
    src/reflectanceSensor.cpp
    src/sensor.cpp
)

target_compile_options(sensors PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(sensors PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(sensors PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_link_libraries(sensors PRIVATE iHal)
target_link_libraries(sensors PRIVATE iHw)
