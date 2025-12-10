//
// Created by curse on 12/10/25.
//

#include <cstdio>
#include "../../AdjacencyListUndirectedGraph.h"

// tests all 0 inputs, which should do nothing
int main() {
    AdjacencyListUndirectedGraph g;
    g.addBinarySubtree(0, 0, 0, 0);
    printf("%d\n", g.getVertexCount());
}
