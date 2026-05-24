cmake_minimum_required(VERSION 3.20)

project(esercitazione5)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

add_executable(test_sorts
        test_sorts.cpp
)

add_executable(measure_sorts
        measure_sorts.cpp
)