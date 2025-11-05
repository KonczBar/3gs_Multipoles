//
// Created by curse on 11/5/25.
//
#include <cstdio>
#include <stdexcept>

#include "../../AdjacencyListUndirectedGraph.h"

// attempts to add edge between 0 and 0
// should fail
int main() {
    AdjacencyListUndirectedGraph g;
    try {
        g.addEdge(0,0);
        return 0;
    } catch (invalid_argument e) {
        return 1;
    }

}