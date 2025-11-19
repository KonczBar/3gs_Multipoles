cmake_minimum_required(VERSION 4.0)
project(multiples)

set(CMAKE_CXX_STANDARD 20)

add_executable(multipoles main.cpp
        AdjacencyListUndirectedGraph.cpp
        AdjacencyListUndirectedGraph.h
        IntervalSkippingIterator.cpp
        IntervalSkippingIterator.h
)

enable_testing()

# tests for basic graph class

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


# tests for range set and range skipping iterator

add_executable(rangeTest1 tests/IteratorTest/RangeTest1.cpp
        IntervalSkippingIterator.cpp
        IntervalSkippingIterator.h)
add_test(rangeTest1 rangeTest1)
set_tests_properties(rangeTest1 PROPERTIES PASS_REGULAR_EXPRESSION "0")


add_executable(rangeTest2 tests/IteratorTest/RangeTest2.cpp
        IntervalSkippingIterator.h
        IntervalSkippingIterator.cpp)
add_test(rangeTest2 rangeTest2)
set_tests_properties(rangeTest2 PROPERTIES WILL_FAIL TRUE)


add_executable(rangeTest3 tests/IteratorTest/RangeTest3.cpp
        IntervalSkippingIterator.cpp
        IntervalSkippingIterator.h)
add_test(rangeTest3 rangeTest3)
set_tests_properties(rangeTest3 PROPERTIES PASS_REGULAR_EXPRESSION "4")


add_executable(rangeTest4 tests/IteratorTest/RangeTest4.cpp
        IntervalSkippingIterator.h
        IntervalSkippingIterator.cpp)
add_test(rangeTest4 rangeTest4)
set_tests_properties(rangeTest4 PROPERTIES WILL_FAIL TRUE)


add_executable(rangeTest5 tests/IteratorTest/RangeTest5.cpp
        IntervalSkippingIterator.cpp
        IntervalSkippingIterator.h)
add_test(rangeTest5 rangeTest5)
set_tests_properties(rangeTest5 PROPERTIES WILL_FAIL TRUE)


add_executable(skipTest1 tests/IteratorTest/SkipTest1.cpp
        IntervalSkippingIterator.h
        IntervalSkippingIterator.cpp)
add_test(skipTest1 skipTest1)
set_tests_properties(skipTest1 PROPERTIES WILL_FAIL TRUE)


add_executable(skipTest2 tests/IteratorTest/SkipTest2.cpp
        IntervalSkippingIterator.cpp
        IntervalSkippingIterator.h)
add_test(skipTest2 skipTest2)
set_tests_properties(skipTest2 PROPERTIES PASS_REGULAR_EXPRESSION "0 1 2 3 4 5 6 7 8 9 end")


add_executable(skipTest3 tests/IteratorTest/SkipTest3.cpp
        IntervalSkippingIterator.h
        IntervalSkippingIterator.cpp)
add_test(skipTest3 skipTest3)
set_tests_properties(skipTest3 PROPERTIES PASS_REGULAR_EXPRESSION ^6\n)


add_executable(skipTest4 tests/IteratorTest/SkipTest4.cpp
        IntervalSkippingIterator.cpp
        IntervalSkippingIterator.h)
add_test(skipTest4 skipTest4)
set_tests_properties(skipTest4 PROPERTIES PASS_REGULAR_EXPRESSION ^0\n)


# tests for complete binary tree - dependant on adjacency list undirected graph

add_executable(binTreeTest1 tests/GraphTest/BinTreeTest1.cpp
        AdjacencyListUndirectedGraph.cpp
        AdjacencyListUndirectedGraph.h)
add_test(binTreeTest1 binTreeTest1)
set_tests_properties(binTreeTest1 PROPERTIES PASS_REGULAR_EXPRESSION ^1\n)


add_executable(binTreeTest2 tests/GraphTest/BinTreeTest2.cpp
        AdjacencyListUndirectedGraph.h
        AdjacencyListUndirectedGraph.cpp)
add_test(binTreeTest2 binTreeTest2)
set_tests_properties(binTreeTest2 PROPERTIES PASS_REGULAR_EXPRESSION ^15\n)
