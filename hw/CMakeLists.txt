add_subdirectory(interface)
add_subdirectory(adcs)
add_subdirectory(pins)
add_subdirectory(timers)
add_subdirectory(uart)
add_subdirectory(lcd)

add_library(hw STATIC OBJECT
    $<TARGET_OBJECTS:hwAdc>
    $<TARGET_OBJECTS:hwPin>
    $<TARGET_OBJECTS:hwTimer>
    $<TARGET_OBJECTS:hwUart>
    $<TARGET_OBJECTS:hwLcd>
)

target_link_libraries(hw PRIVATE iHw)