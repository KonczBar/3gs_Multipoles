#include <cassert>
#include <cmath>
#include <cstdio>

#include "AdjacencyListUndirectedGraph.h"
using namespace std;

// function that returns M(k,g)
// (the Moore Bound for a k-regular graph with girth g)
/*
int getMooreBound(int k, int g) {
    assert (g > 2);
    if (g % 2 == 0) {
        return (2 * pow(k - 1, g / 2) - 2) / (k - 2);
    } else if (g % 2 == 1) {
        return (k * pow(k - 1, (g - 1) / 2) - 2) / (k - 2);
    }
}
*/



int main() {
    AdjacencyListUndirectedGraph g;
    for (int i = 0; i < 7; i++) {
        g.addEdge(i, i + 1);
    }
    g.print();
    printf("vertices: %d, undirected edges: %d \n", g.getVertexCount(), g.getUndirectedEdgeCount());


    return 0;
}


