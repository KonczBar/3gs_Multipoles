//
// Created by curse on 10/21/25.
//


#ifndef UNTITLED_ADJACENCYLISTUNDIRECTEDGRAPH_H
#define UNTITLED_ADJACENCYLISTUNDIRECTEDGRAPH_H

#include <vector>
using namespace std;


class AdjacencyListUndirectedGraph {
private:
    int n;
    vector<int> degrees;
    vector<int*> adjacencyList;
public:
    explicit AdjacencyListUndirectedGraph(int initialSize);
    virtual ~AdjacencyListUndirectedGraph() = default;
    virtual void addEdge(int u, int v);
    virtual void print();
};


#endif //UNTITLED_ADJACENCYLISTUNDIRECTEDGRAPH_H