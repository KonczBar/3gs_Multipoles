//
// Created by curse on 11/5/25.
//

#include <cstdio>

#include "../../AdjacencyListUndirectedGraph.h"

int main() {
    AdjacencyListUndirectedGraph g;
    g.addVertices(9);
    printf("%d %d\n", g.getUndirectedEdgeCount(), g.getVertexCount());
}
