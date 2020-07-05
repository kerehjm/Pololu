add_library(mocks INTERFACE)

target_include_directories(mocks INTERFACE hal)
target_include_directories(mocks INTERFACE hw)
