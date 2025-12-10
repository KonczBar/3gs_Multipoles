//
// Created by curse on 12/10/25.
//

#include <cstdio>

#include "../../AdjacencyListUndirectedGraph.h"

int main() {
    AdjacencyListUndirectedGraph g;
    g.addVertices(5);
    g.addBinarySubtree(5, 5, 0, 2);
    printf("%d %d", g.getVertexCount(), g.getUndirectedEdgeCount());
}
