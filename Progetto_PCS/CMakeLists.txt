cmake_minimum_required(VERSION 3.20)

project(progetto LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(
    -Wall
    -Wextra
    -Wshadow
)

find_package(Eigen3 REQUIRED)

add_executable(progetto
    progetto.cpp
)

target_link_libraries(progetto
    PRIVATE
    Eigen3::Eigen
)