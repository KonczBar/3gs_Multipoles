//
// Created by curse on 10/29/25.
//

#include <cstdio>
#include "../../AdjacencyListUndirectedGraph.h"

// empty graph
int main() {
    AdjacencyListUndirectedGraph g;
    printf("%d %d\n", g.getUndirectedEdgeCount(), g.getVertexCount());
}
