//
// Created by curse on 3/3/26.
//

#include <stdexcept>

#include "../../AdjacencyListUndirectedGraph.h"

int main() {
    AdjacencyListUndirectedGraph g;
    g.addVertices(1);
    // testing cutSemiEdge, joinSemiEdges

    g.addVertices(1);

    try {
        g.joinSemiEdges(0,1);
        return 1;
    } catch (invalid_argument &e) {
    }

    g.addSemiEdge(0);
    g.addSemiEdge(1);
    g.addSemiEdge(1);

    g.joinSemiEdges(0,1);

    try {
        g.joinSemiEdges(0,1);
        return 1;
    } catch (invalid_argument &e) {
    }

    printf("%d %d ", g.semiEdgeCount(0), g.semiEdgeCount(1));

    g.cutEdge(0,1);
    printf("%d %d\n", g.semiEdgeCount(0), g.semiEdgeCount(1));

    try {
        g.cutEdge(0,1);
        return 1;
    } catch (invalid_argument &e) {
    }
}
