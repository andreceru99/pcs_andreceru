cmake_minimum_required(VERSION 3.20)

project(esercitazione10)

set(CMAKE_CXX_STANDARD 20)

find_package(Eigen3 REQUIRED)

add_executable(
    test_gradiente_coniugato
    test_gradiente_coniugato.cpp
)

add_executable(
    gradiente_vicini
    gradiente_Vicini.cpp
)

target_link_libraries(
    test_gradiente_coniugato
    Eigen3::Eigen
)

target_link_libraries(
    gradiente_vicini
    Eigen3::Eigen
)