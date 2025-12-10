//
// Created by curse on 12/10/25.
//

#include <cstdio>

#include "../../AdjacencyListUndirectedGraph.h"

int main() {
    AdjacencyListUndirectedGraph g;
    g.addBinarySubtree(0, 0, 0, 2);
    printf("%d %d\n", g.getVertexCount(), g.getUndirectedEdgeCount());
}
