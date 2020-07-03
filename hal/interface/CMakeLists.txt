add_library(iHal INTERFACE)

target_include_directories(iHal INTERFACE inc)

target_link_libraries(iHal INTERFACE iHw)
