#include <iostream>
#include <vector>

#define SEMIEDGE (-1)
#define UNDEFINED (-2)

// TODO: redundancy with UNDEFINED and degree constraints?

using namespace std;

// check if graph satisfies girth constraints by doing BFS from source node
int checkGirth() {
    return 0; // TODO
}


// initializes recursion for searching for multipoles with the characteristics:
// girth G
// S semi-edges
// N total vertices
int start (const int G, const int S, const int N) {
    vector<vector<int>> v(N);            // adjacency list, only contains u->v for u < v
    vector<int> h(N, UNDEFINED);    // depths nodes appear at during BFS from vertex 0
    vector<int> d(N, 0);             // degrees of vertices

    for (int i = 0; i < N; i++) {
        v.at(i).reserve(3);
    }

    int p = 0;              // current element
    int next_depth = 1;     // first element of next depth

    v.at(0).push_back(1); // graph is always initialized to 0 - 1
    h.at(1) = 1;
    d.at(0) = 1;
    d.at(1) = 1;

    while (true) {
        while (d.at(p) < 3) {
            //TODO
        }
    }
}









int main() {
    return 0;
}