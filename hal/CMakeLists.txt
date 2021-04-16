add_subdirectory(buttons)
add_subdirectory(interface)
add_subdirectory(leds)
add_subdirectory(motors)
add_subdirectory(myDebug)
add_subdirectory(pins)
add_subdirectory(sensors)
add_subdirectory(timers)
add_subdirectory(pwm)
add_subdirectory(lcd)

add_library(hal STATIC OBJECT
    $<TARGET_OBJECTS:halLcd>
    $<TARGET_OBJECTS:buttons>
    $<TARGET_OBJECTS:leds>
    $<TARGET_OBJECTS:motors>
    $<TARGET_OBJECTS:myDebug>
    $<TARGET_OBJECTS:pins>
    $<TARGET_OBJECTS:sensors>
    $<TARGET_OBJECTS:timers>
    $<TARGET_OBJECTS:pwm>
)
target_link_libraries(hal PRIVATE iHal)
