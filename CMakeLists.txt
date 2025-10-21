cmake_minimum_required(VERSION 4.0)
project(multiples)

set(CMAKE_CXX_STANDARD 20)

add_executable(multipoles main.cpp
        AdjacencyListUndirectedGraph.cpp
        AdjacencyListUndirectedGraph.h
)
