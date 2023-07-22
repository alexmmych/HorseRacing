# Initialization
cmake_minimum_required(VERSION 3.22.1)
project(HorseRacing VERSION 1.2.0)

# Includes the class header files
include_directories(${CMAKE_SOURCE_DIR}/include)

# Link and build the executable
add_library(HorseMatrix HorseMatrix.cpp)
add_executable(HorseRacing main.cpp)
target_link_libraries(HorseRacing HorseMatrix)
