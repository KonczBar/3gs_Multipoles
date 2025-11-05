//
// Created by curse on 11/5/25.
//

#include <cstdio>
#include "../../AdjacencyListUndirectedGraph.h"

// loop of 10
int main() {
    AdjacencyListUndirectedGraph g;
    for (int i = 0; i < 9; i++) {
        g.addEdge(i, i+1);
    }

    g.addEdge(0, 9);

    printf("%d %d\n", g.getUndirectedEdgeCount(), g.getVertexCount());
}