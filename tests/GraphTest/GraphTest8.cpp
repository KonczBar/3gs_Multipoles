//
// Created by curse on 12/10/25.
//

#include <stdexcept>

#include "../../AdjacencyListUndirectedGraph.h"
// testing that same edge cannot be added twice
int main() {
    try {
        AdjacencyListUndirectedGraph g;
        g.addEdge(0, 1);
        g.addEdge(1, 0);
    } catch (invalid_argument const &e) {
        return 1;
    }
}