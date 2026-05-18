cmake_minimum_required(VERSION 3.20)

project(esercitazione9)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

add_executable(test_containers test_containers.cpp)

add_executable(
    test_graph_visit
    test_graph_visit.cpp
    unidirected_graph.cpp
    unidirected_edge.cpp
)

add_executable(
    test_dijkstra
    test_dijkstra.cpp
    unidirected_graph.cpp
    unidirected_edge.cpp

)