//
// Created by curse on 12/10/25.
//

#include "../../AdjacencyListUndirectedGraph.h"

// checking hasEdge function
int main() {
    AdjacencyListUndirectedGraph g;
    g.addEdge(2, 3);
    g.addEdge(1, 0);
    g.addEdge(7, 3);
    g.addEdge(50, 3);

    bool correct = true;

    correct = g.hasEdge(2,3) && g.hasEdge(3,2) && g.hasEdge(1,0) && g.hasEdge(0,1) && g.hasEdge(7,3)
        && g.hasEdge(3, 7) && g.hasEdge(50, 3);

    if (correct) {
        return 0;
    } else {
        return 1;
    }
}