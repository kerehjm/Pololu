add_library(halSensors STATIC OBJECT
    src/proximitySensor.cpp
    src/reflectanceSensor.cpp
    src/sensor.cpp
)

target_compile_options(halSensors PRIVATE "$<$<CONFIG:DEBUG>:${AVR_DEBUG_BUILD_FLAGS}>")
target_compile_options(halSensors PRIVATE "$<$<CONFIG:RELEASE>:${AVR_RELEASE_BUILD_FLAGS}>")

target_include_directories(halSensors PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)

target_link_libraries(halSensors PRIVATE iHal)
target_link_libraries(halSensors PRIVATE iHw)
