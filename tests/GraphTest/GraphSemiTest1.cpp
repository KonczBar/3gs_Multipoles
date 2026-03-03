//
// Created by curse on 3/3/26.
//

#include <cstdio>
#include <stdexcept>

#include "../../AdjacencyListUndirectedGraph.h"

int main() {
    // testing addSemiEdge, semiEdgeCount
    AdjacencyListUndirectedGraph g;
    printf("%d ", g.semiEdgeCount(0));

    g.addVertices(0);
    g.addSemiEdge(0);
    g.addSemiEdge(0);
    g.addSemiEdge(0);

    printf("%d\n", g.semiEdgeCount(0));

    try {
        g.addSemiEdge(0);
        return 1;
    } catch (runtime_error &e) {
        return 0;
    }
}
