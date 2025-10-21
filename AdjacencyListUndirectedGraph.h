//
// Created by curse on 10/21/25.
//


#ifndef UNTITLED_ADJACENCYLISTUNDIRECTEDGRAPH_H
#define UNTITLED_ADJACENCYLISTUNDIRECTEDGRAPH_H

#include <vector>
using namespace std;


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
    //virtual int getUndirectedEdgeCount() = 0;
};


#endif //UNTITLED_ADJACENCYLISTUNDIRECTEDGRAPH_H