//
// Created by curse on 10/21/25.
//


#ifndef UNTITLED_ADJACENCYLISTUNDIRECTEDGRAPH_H
#define UNTITLED_ADJACENCYLISTUNDIRECTEDGRAPH_H

#include <vector>
using namespace std;


/* Graph class for the project */

/*      Has a variable size
 *      May contain semiedges (denoted as -1 in the adjacency list)
 *      Allows at most degree 3 for vertices
 */


class AdjacencyListUndirectedGraph {
private:
    int size;
    vector<int> degrees;
    vector<int*> adjacency_list;

public:
    AdjacencyListUndirectedGraph();
    ~AdjacencyListUndirectedGraph();
    void addEdge(int u, int v); // expands graph so that u and v exist
    void addVertices(int u); // adds all vertices up to and including u
    void print() const;
    [[nodiscard]] int getVertexCount() const;
    [[nodiscard]] int getUndirectedEdgeCount() const;
    int addBinarySubtree(int vertex, int offset, int depth, int max_depth);
};


/* Complete binary tree - PROBABLY DEPRECATED
 * creates a complete binary tree that has all its leaves in depth d
 * 'root' is 0 (it has one free edge)
 * 'leaves' in depth d have 2 free edges
 * vertex i is the "parent" of vertex 2i + 1 and 2i + 2 (actual parent-child relations not defined), edges undirected
 */

class CompleteBinaryTree final : public AdjacencyListUndirectedGraph {
private:
    int max_depth;
    void addChildren(int vertex, int depth);
public:
    explicit CompleteBinaryTree(int max_depth);
};


#endif //UNTITLED_ADJACENCYLISTUNDIRECTEDGRAPH_H