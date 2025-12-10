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
    while (!adjacency_list.empty()) {
        delete[] adjacency_list.back();
        adjacency_list.pop_back();
    }
}

// Has Edge
//  checks if edge exists between u and v
bool AdjacencyListUndirectedGraph::hasEdge(const int u, const int v) const {
    if (u < 0 || v < 0) {
        throw invalid_argument("Vertex cannot be negative");
    }

    // one or more vertex doesn't exist
    if (u >= size || v >= size) {
        return false;
    }

    // searches neighbours of u for v
    // assumes that self is undirected (if it somehow isn't, something has gone terribly wrong)
    for (int i = 0; i < degrees.at(u); i++) {
        if (adjacency_list.at(u)[i] == v) {
            return true;
        }
    }

    return false;
}

// Semi-edge Count
//  Returns number of semi-edges incident to v
// TODO: test
int AdjacencyListUndirectedGraph::semiEdgeCount(const int v) const {
    if (v < 0) {
        throw invalid_argument("Vertex cannot be negative");
    }

    // v doesn't exist
    if (v >= size) {
        return 0;
    }

    int count = 0;

    // searches edges of v
    for (int i = 0; i < degrees.at(v); i++) {
        if (adjacency_list.at(v)[i] == -1) {
            count++;
        }
    }

    return count;
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


// Cut Edge
//  Replaces edge from u to v with u to -1
//  Replaces edge from v to u with v to -1
// TODO: test
void AdjacencyListUndirectedGraph::cutEdge(const int u, const int v) const {
    if (!hasEdge(u, v)) {
        throw invalid_argument("Cannot cut edge between u and v: it does not exist");
    }


    // replaces edge from u to v with semi-edge (-1)
    for (int i = 0; i < degrees.at(u); i++) {
        if (adjacency_list.at(u)[i] == v) {
            adjacency_list.at(u)[i] = -1;
            break;
        }
    }

    // replaces edge from v to u with semi-edge (-1)
    for (int i = 0; i < degrees.at(v); i++) {
        if (adjacency_list.at(v)[i] == u) {
            adjacency_list.at(v)[i] = -1;
            break;
        }
    }
}

// Join Semi-Edges
//  Replaces semi-edge of u with edge to v
//  Replaces semi-edge of v with edge to u
// TODO: test
void AdjacencyListUndirectedGraph::joinSemiEdges(const int u, const int v) const {
    if (!hasEdge(u,v)) {
        throw invalid_argument("Cannot join semi-edges of u and v: Edge between u and v already exists");
    }

    if (semiEdgeCount(u) < 1 || semiEdgeCount(v) < 1) {
        throw invalid_argument("Cannot join semi-edges of u and v: u or v doesn't have semi-edge");
    }

    // replaces semi-edge from u with edge to v
    for (int i = 0; i < degrees.at(u); i++) {
        if (adjacency_list.at(u)[i] == -1) {
            adjacency_list.at(u)[i] = v;
            break;
        }
    }

    // replaces semi-edge from v with edge to u
    for (int i = 0; i < degrees.at(v); i++) {
        if (adjacency_list.at(v)[i] == -1) {
            adjacency_list.at(v)[i] = u;
            break;
        }
    }
}


// Add Edge
//  adds an edge between vertices u and v
//  if one or more vertices don't exist, expands the graph to fit them
void AdjacencyListUndirectedGraph::addEdge(const int u, const int v) {
    if (u < 0 || v < 0) {
        throw invalid_argument("Vertex cannot be negative");
    }

    if (u == v) {
        throw invalid_argument("Attempted to add edge between v and v");
    }

    if (hasEdge(u,v)) {
        throw invalid_argument("Cannot add edge between u and v: it already exists");
    }

    // if uninitialized, initializes arrays that can hold up to 3 neighbouring vertices
    // (enough for 3-reg graph)
    addVertices(max(u,v));

    // this error cannot be recovered from as additional vertices might have been added
    if (degrees.at(u) == 3 || degrees.at(v) == 3) {
        throw runtime_error("Attempted to add 4th incident edge - invalid for 3-regular graph.");
    }



    // write edge to adjacency list
    adjacency_list.at(u)[degrees[u]] = v;
    adjacency_list.at(v)[degrees[v]] = u;

    // increment degrees of u and v
    degrees.at(u)++;
    degrees.at(v)++;
}

// Add Semi-edge
//  Adds a semi-edge to vertex v, represented as an edge to -1
//  Normal rules for edges apply, degree cannot be over 3
// TODO: test
void AdjacencyListUndirectedGraph::addSemiEdge(const int v) {
    if (v < 0) {
        throw invalid_argument("Vertex cannot be negative");
    }

    // if v doesn't exist, all vertices up to and including v are created
    addVertices(v);

    if (degrees.at(v) == 3) {
        throw runtime_error("Attempted to add 4th incident edge - invalid for 3-regular graph");
    }

    // write edge to adjacency list
    adjacency_list.at(v)[degrees[v]] = -1;

    // increment degree of v
    degrees.at(v)++;
}


// Get Vertex Count
//  returns number of vertices
int AdjacencyListUndirectedGraph::getVertexCount() const {
    return size;
}


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



/* creates a complete binary tree within g so that:
* the 'root' is vertex
* all leaves are max_depth distance from root
* if vertex is the 'parent' of left and right, the following applies:
* left = 2 * (vertex - offset) + 1 + offset = 2 * vertex + 1 - offset
* right = 2 * (vertex - offset) + 2 + offset = 2 * vertex + 2 - offset
*
* return value: size of the tree
*
* does not explicitly throw errors if the vertices to be included already exist
* but if such a vertex is within the middle of the tree, it will inevitably result in one due to the max 3-reg rule
*
* as per the mechanisms of vertex addition, if the vertex is higher than current vertex count, the preceding vertices
* are implicitly created as vertices with 0 edges
*
* TODO: more tests in the future
*/

int AdjacencyListUndirectedGraph::addBinarySubtree(const int vertex, const int offset, const int depth, const int max_depth) {
    if (depth == max_depth) {
        return 1;
    }

    const int left = 2 * vertex + 1 - offset;
    this->addEdge(vertex, left);
    const int left_size = addBinarySubtree(left, offset, depth + 1, max_depth);

    const int right = 2 * vertex + 2 - offset;
    this->addEdge(vertex, right);
    const int right_size = addBinarySubtree(right, offset, depth + 1, max_depth);

    return left_size + right_size + 1;
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
    this->addVertices(0);
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



