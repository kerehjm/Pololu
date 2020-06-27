add_library(timers STATIC OBJECT
    src/timer0.cpp
    src/timer1.cpp
    src/timer2.cpp
    src/timerFactory.cpp)
    
target_include_directories(timers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
