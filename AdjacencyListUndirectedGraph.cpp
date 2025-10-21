//
// Created by curse on 10/20/25.
//

#include <set>
#include <cassert>
#include <cstdio>
#include <vector>
#include "AdjacencyListUndirectedGraph.h"
using namespace std;

AdjacencyListUndirectedGraph::AdjacencyListUndirectedGraph(const int initialSize) {
    n = initialSize;
    for (int i = 0; i < n; i++) {
        degrees.push_back(0);
        adjacencyList.push_back(new int[3]); // since k-regular and everything will be filled in, anyway
    }
}

void AdjacencyListUndirectedGraph::addEdge(const int u, const int v) {
    //assert(degrees.at(u) <= 3 && degrees.at(v) <= 3 && "Error: vertex degree too high");
    assert(u < n && v < n && "Error: vertex overflow");
    assert(u != v && "Error: Edge between v and v not allowed");
    adjacencyList.at(u)[degrees[u]] = v;
    adjacencyList.at(v)[degrees[v]] = u;
    degrees.at(u)++;
    degrees.at(v)++;
}

void AdjacencyListUndirectedGraph::print() {
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < degrees.at(i); j++) {
            printf("%d ", adjacencyList.at(i)[j]);
        }
        printf("\n");
    }
}