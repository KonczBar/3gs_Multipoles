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
    vector<int*> adjacencyList;

public:
    explicit AdjacencyListUndirectedGraph();
    virtual ~AdjacencyListUndirectedGraph();
    virtual void addEdge(int u, int v);
    virtual void addVertices(int u);
    virtual void print();
    virtual int getVertexCount();
    virtual int getUndirectedEdgeCount();
};


#endif //UNTITLED_ADJACENCYLISTUNDIRECTEDGRAPH_H