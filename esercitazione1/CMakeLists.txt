cmake_minimum_required(VERSION 3.20)
project(esercitazione1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SOURCES argomenti.cpp file1.cpp)

add_executable(argomenti argomenti.cpp)
add_executable(file1 file1.cpp)