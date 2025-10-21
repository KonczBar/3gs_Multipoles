//
// Created by curse on 10/20/25.
//

#include <set>
#include <cassert>
#include <cstdio>
#include <vector>
#include "AdjacencyListUndirectedGraph.h"
using namespace std;


AdjacencyListUndirectedGraph::AdjacencyListUndirectedGraph() {
    size = 0;
}

AdjacencyListUndirectedGraph::~AdjacencyListUndirectedGraph() {
    for (int i = 0; i < adjacencyList.size(); i++) {
        delete[] adjacencyList.back();
        adjacencyList.pop_back();
    }
}

// adds all vertices up to and including u
// if u already exists, it does nothing

void AdjacencyListUndirectedGraph::addVertices(const int u) {
    if (adjacencyList.size() > u) {
        return;
    }

    if (adjacencyList.size() < u) {
        addVertices(u - 1);
    }

    assert(adjacencyList.size() == u);

    adjacencyList.push_back(new int[3]);
    degrees.push_back(0);
}


void AdjacencyListUndirectedGraph::addEdge(const int u, const int v) {
    // assert(degrees.at(u) <= 3 && degrees.at(v) <= 3 && "Error: vertex degree too high");
    // assert(u < n && v < n && "Error: vertex overflow");
    assert(u != v && "Error: Edge between v and v not allowed");

    // if uninitialized, initializes arrays that can hold up to 3 neighbouring vertices
    // (enough for 3-reg graph)
    addVertices(max(u,v));

    // write edge to adjacency list
    adjacencyList.at(u)[degrees[u]] = v;
    adjacencyList.at(v)[degrees[v]] = u;

    // increment degrees of u and v
    degrees.at(u)++;
    degrees.at(v)++;
}

void AdjacencyListUndirectedGraph::print() {

    for (int i = 0; i < adjacencyList.size(); i++) {
        printf("%d: ", i);
        for (int j = 0; j < degrees.at(i); j++) {
            printf("%d ", adjacencyList.at(i)[j]);
        }
        printf("\n");
    }
}




int AdjacencyListUndirectedGraph::getVertexCount() {
    return adjacencyList.size(); // currently, sizing isn't dynamic so that's the next thing to implement
}

