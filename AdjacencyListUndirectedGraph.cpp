//
// Created by curse on 10/20/25.
//

#include <set>
#include <cassert>
#include <stdexcept>
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
    for (int i = 0; i < adjacency_list.size(); i++) {
        delete[] adjacency_list.back();
        adjacency_list.pop_back();
    }
}



// Add Vertices
//  adds all vertices up to and including u
//  if u already exists, it does nothing
void AdjacencyListUndirectedGraph::addVertices(const int u) {
    //assert(u >= 0);
    if (u < 0) {
        throw invalid_argument("Attempted to add vertex of negative value");
    }

    // if u is present, does nothing
    if (adjacency_list.size() > u) {
        return;
    }

    // if vertices before u are missing, adds them
    if (adjacency_list.size() < u) {
        addVertices(u - 1);
    }

    assert(adjacency_list.size() == u);

    // allocates new edges, pushes degree, increments graph size
    adjacency_list.push_back(new int[3]);
    degrees.push_back(0);
    size++;
}



// Add Edge
//  adds an edge between vertices u and v
//  if one or more vertices don't exist, expands the graph to fit them
void AdjacencyListUndirectedGraph::addEdge(const int u, const int v) {
    if (u == v) {
        throw invalid_argument("Attempted to add edge between v and v");
    }

    // if uninitialized, initializes arrays that can hold up to 3 neighbouring vertices
    // (enough for 3-reg graph)
    addVertices(max(u,v));

    if (degrees.at(u) == 3 || degrees.at(v) == 3) {
        throw runtime_error("Attempted to add 4th incident edge - invalid for 3-regular graph");
    }



    // write edge to adjacency list
    adjacency_list.at(u)[degrees[u]] = v;
    adjacency_list.at(v)[degrees[v]] = u;

    // increment degrees of u and v
    degrees.at(u)++;
    degrees.at(v)++;
}



// Get Vertex Count
//  returns number of vertices
int AdjacencyListUndirectedGraph::getVertexCount() const {
    return size;
}




/* DEBUG FUNCTIONS */

// Get Undirected Edge Count
//  Semiedges do not count towards the total
int AdjacencyListUndirectedGraph::getUndirectedEdgeCount() const {
    int edgeCount = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < degrees.at(i); j++) {
            if (adjacency_list.at(i)[j] != -1) {
                edgeCount++;
            }
        }
    }

    assert(edgeCount % 2 == 0);

    return edgeCount / 2;
}



// recursively add all child nodes
void CompleteBinaryTree::addChildren(const int vertex, const int depth) {
    if (depth == max_depth) {
        return;
    }

    const int left = 2 * vertex + 1;
    const int right = 2 * vertex + 2;
    this->addEdge(vertex, left);
    addChildren(left, depth + 1);

    this->addEdge(vertex, right);
    addChildren(right, depth + 1);

}

CompleteBinaryTree::CompleteBinaryTree(const int max_depth) {
    this->max_depth = max_depth;
    this->AdjacencyListUndirectedGraph::addVertices(0);
    this->addChildren(0, 0);
}


// Print Graph
//  for testing purposes
void AdjacencyListUndirectedGraph::print() const {

    for (int i = 0; i < size; i++) {
        printf("%d: ", i);
        for (int j = 0; j < degrees.at(i); j++) {
            printf("%d ", adjacency_list.at(i)[j]);
        }
        printf("\n");
    }
}



