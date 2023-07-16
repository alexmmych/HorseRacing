cmake_minimum_required(VERSION 3.22.1)
project(HorseRacing VERSION 1.2.0)


include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(HorseMatrix HorseMatrix.cpp)

add_executable(HorseRacing main.cpp)

target_link_libraries(HorseRacing HorseMatrix)
