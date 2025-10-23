//
// Created by curse on 10/20/25.
//

#include <set>
#include <cassert>
#include <cstdio>
#include <vector>
#include "AdjacencyListUndirectedGraph.h"
using namespace std;

// Constructor
AdjacencyListUndirectedGraph::AdjacencyListUndirectedGraph() {
    size = 0;
}

// Destructor
AdjacencyListUndirectedGraph::~AdjacencyListUndirectedGraph() {
    for (int i = 0; i < adjacencyList.size(); i++) {
        delete[] adjacencyList.back();
        adjacencyList.pop_back();
    }
}



// Add Vertices
//  adds all vertices up to and including u
//  if u already exists, it does nothing
void AdjacencyListUndirectedGraph::addVertices(const int u) {
    assert(u >= 0);

    // if u is present, does nothing
    if (adjacencyList.size() > u) {
        return;
    }

    // if vertices before u are missing, adds them
    if (adjacencyList.size() < u) {
        addVertices(u - 1);
    }

    assert(adjacencyList.size() == u);

    // allocates new edges, pushes degree, increments graph size
    adjacencyList.push_back(new int[3]);
    degrees.push_back(0);
    size++;
}



// Add Edge
//  adds an edge between vertices u and v
//  if one or more vertices don't exist, expands the graph to fit them
void AdjacencyListUndirectedGraph::addEdge(const int u, const int v) {
    assert(u != v && "Error: Edge between v and v not allowed");

    // if uninitialized, initializes arrays that can hold up to 3 neighbouring vertices
    // (enough for 3-reg graph)
    addVertices(max(u,v));
    assert(degrees.at(u) <= 3 && degrees.at(v) <= 3 && "Error: vertex degree too high");

    // write edge to adjacency list
    adjacencyList.at(u)[degrees[u]] = v;
    adjacencyList.at(v)[degrees[v]] = u;

    // increment degrees of u and v
    degrees.at(u)++;
    degrees.at(v)++;
}



// Get Vertex Count
//  returns number of vertices
int AdjacencyListUndirectedGraph::getVertexCount() {
    return size;
}




/* DEBUG FUNCTIONS */

// Get Undirected Edge Count
//  Semiedges do not count towards the total
int AdjacencyListUndirectedGraph::getUndirectedEdgeCount() {
    int edgeCount = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < degrees.at(i); j++) {
            if (adjacencyList.at(i)[j] != -1) {
                edgeCount++;
            }
        }
    }

    assert(edgeCount % 2 == 0);

    return edgeCount / 2;
}


// Print Graph
//  for testing purposes
void AdjacencyListUndirectedGraph::print() {

    for (int i = 0; i < size; i++) {
        printf("%d: ", i);
        for (int j = 0; j < degrees.at(i); j++) {
            printf("%d ", adjacencyList.at(i)[j]);
        }
        printf("\n");
    }
}



