add_library(myDebug STATIC
    myDebug.cpp)

target_include_directories(myDebug PUBLIC ../../hw/uart) #understand why public
target_link_libraries(myDebug PRIVATE uart)
