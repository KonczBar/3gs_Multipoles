cmake_minimum_required(VERSION 4.0)
project(multiples)

set(CMAKE_CXX_STANDARD 20)

add_executable(multipoles main.cpp
        AdjacencyListUndirectedGraph.cpp
        AdjacencyListUndirectedGraph.h
)

enable_testing()

add_executable(graphTest1 tests/GraphTest/GraphTest1.cpp
        AdjacencyListUndirectedGraph.h
        AdjacencyListUndirectedGraph.cpp)
add_test(graphTest1 graphTest1)
set_tests_properties(graphTest1 PROPERTIES PASS_REGULAR_EXPRESSION "0 0")


add_executable(graphTest2 tests/GraphTest/GraphTest2.cpp
        AdjacencyListUndirectedGraph.cpp
        AdjacencyListUndirectedGraph.h)
add_test(graphTest2 graphTest2)
set_tests_properties(graphTest2 PROPERTIES PASS_REGULAR_EXPRESSION "9 10")


add_executable(graphTest3 tests/GraphTest/GraphTest3.cpp
            AdjacencyListUndirectedGraph.h
            AdjacencyListUndirectedGraph.cpp)
add_test(graphTest3 graphTest3)
set_tests_properties(graphTest3 PROPERTIES PASS_REGULAR_EXPRESSION "10 10")


add_executable(graphTest4 tests/GraphTest/GraphTest4.cpp
        AdjacencyListUndirectedGraph.cpp
        AdjacencyListUndirectedGraph.h)
add_test(graphTest4 graphTest4)
set_tests_properties(graphTest4 PROPERTIES WILL_FAIL TRUE)

add_executable(graphTest5 tests/GraphTest/GraphTest5.cpp
        AdjacencyListUndirectedGraph.cpp
        AdjacencyListUndirectedGraph.h)
add_test(graphTest5 graphTest5)
set_tests_properties(graphTest5 PROPERTIES WILL_FAIL TRUE)

add_executable(graphTest6 tests/GraphTest/GraphTest6.cpp
        AdjacencyListUndirectedGraph.h
        AdjacencyListUndirectedGraph.cpp)
add_test(graphTest6 graphTest6)
set_tests_properties(graphTest6 PROPERTIES PASS_REGULAR_EXPRESSION "0 10")
