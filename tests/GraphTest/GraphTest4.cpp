//
// Created by curse on 11/5/25.
//

#include <cstdio>
#include <stdexcept>

#include "../../AdjacencyListUndirectedGraph.h"

// tries to add more than 3 neighbours to a node
// should fail
int main() {
    AdjacencyListUndirectedGraph g;
    try {
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(0, 3);
        g.addEdge(0, 4);
        return 0;
    } catch (runtime_error e) {
        return 1;
    }
}