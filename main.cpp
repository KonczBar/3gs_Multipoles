#include <cassert>
#include <deque>
#include <iostream>
#include <climits>
#include <unordered_set>
#include <vector>

#define SEMIEDGE (-1)

using namespace std;

// does BFS from the vertex start in the graph defined by v
// returns false if v is a part of a cycle with a size less than G
// true otherwise
bool check_girth(int start, int G, vector<vector<int>>* v) {
    if (G <= 3) {
        return true;
    }

    int max_depth = 1 + ((G - 1) / 2);    // fast ceiling division G/2

    unordered_set<int> visited;
    deque<int> unprocessed;
    vector<int> depth(v->size(), INT_MAX);
    vector<int> parent(v->size(), -1);

    unprocessed.push_back(start);
    depth.at(start) = 0;

    while (!unprocessed.empty()) {
        int next = unprocessed.front();
        unprocessed.pop_front();
        visited.insert(next);

        if (depth.at(next) > max_depth) {
            return true;
        }

        for (int u : v->at(next)) {
            if (u == parent.at(next) || u == -1) {
                continue;
            }

            // girth check failed
            if (visited.contains(u)) {
                if (depth.at(next) + depth.at(u) + 1 < G) {
                    return false;
                }
            } else {
                parent.at(u) = next;
                depth.at(u) = depth.at(next) + 1;
                unprocessed.push_back(u);
            }
        }
    }

    return true;
}

// prints graph
void print_graph(vector<vector<int>>* v) {
    for (int i = 0; i < v->size(); i++) {
        cout << i << ": ";
        for (int c : v->at(i)) {
            cout << c << " ";
        }
        cout << endl;
    }
}

// creates edge from <-> to in v, where from < to or to is a semi-edge
// s points to number of semi-edges available
void make_edge(int from, int to, vector<vector<int>>* v, int* s) {
    assert(v->at(from).size() < 3);

    v->at(from).push_back(to);
    if (to == SEMIEDGE) {
        (*s)--;
        assert(*s >= 0);
    } else {
        v->at(to).push_back(from);
    }
}

// removes the edge last added to from in v
// s points to number of semi-edges
int undo_edge(int from, vector<vector<int>>* v, int* s) {
    int to = v->at(from).back();
    v->at(from).pop_back();

    if (to == SEMIEDGE) {
        (*s)++;
    } else {
        v->at(to).pop_back();
    }

    return to;
}

/** recursively attempts to add edges in a graph of set size,
 * incrementally generating every possible (3,g,s)-multipole of size N
 *
 * G - target minimum girth
 * N - total number of vertices
 * S - target number of semi-edges
 * s - current number of semi-edges
 * p - current target vertex
 * min_next - minimum vertex that p could have edge to (helper variable to counteract some isomorphism)
 * v - adjacency list
 */
void recursion(const int G, const int N, const int S, int s, int p, int min_next, vector<vector<int>>* v) {
    // finds next free stub
    // if none exists, checks success, then returns
    while (v->at(p).size() == 3) {
        p++;
        min_next = p + 1;
        if (p == N) {
            if (s == 0) {
                cout << "Graph found:" << endl;
                print_graph(v);
            }
            return;
        }
    }

    // no free stubs left for remaining semi-edges
    if (3 * N - 2 * (3 * (p - 1) + v->at(p).size()) + S - s < s) {
        return;
    }

    // recursively tries every edge p could have to a vertex of higher index
    //
    int next = min_next;

    while (next < N) {

        // maximum one edge can exist between two vertices
        if (!v->at(p).empty()) {
            if (v->at(p).back() == next) {
                next++;
                continue;
            }
        }

        // the destination vertex must have a free stub
        if (v->at(next).size() < 3) {

            // tries creating edge, checks compliance with grith constraints using BFS
            // the key here is that since no illegal cycles existed before the addition of the edge
            // any newly formed illegal cycles must include p

            make_edge(p, next, v, &s);
            if (check_girth(p, G, v)) {
                recursion(G, N, S, s, p, next, v);
            }
            undo_edge(p, v, &s);

            // if the destination vertex was otherwise completely unused, the cycle will stop
            // (as every vertex after this one is topologically the same and would result in isomorphic graphs)
            if (v->at(next).size() == 0) {
                break;
            }
        }

        next++;
    }

    // lastly, tries to add a semi-edge, if any are available
    if (s > 0) {

        // semi-edge optimization - only adds semi-edges if vertex has no other outgoing edges yet
        // (outgoing = to a vertex of higher index)
        if (!v->at(p).empty()) {
            if (v->at(p).back() > p) {
                return;
            }
        }

        // adding semi-edge does not impact girth
        make_edge(p, SEMIEDGE, v, &s);
        recursion(G, N, S, s, p, next, v);
        undo_edge(p, v, &s);
    }
}


// initializes recursion for searching for multipoles with the characteristics:
// girth G
// S semi-edges
// N total vertices
void start (const int G, const int S, const int N) {
    vector<vector<int>> v(N);               // adjacency list
    vector<int> d(N, 0);               // degrees of vertices

    for (int i = 0; i < N; i++) {
        v.at(i).reserve(3);
    }

    recursion(G, N, S, S, 0, 1, &v);
}

// driver code
int main() {
    int g, s;

    cin >> g >> s;

    int n = 1;
    while (n <= 70) {
        cout << "STARTING SEARCH: N = " << n << endl;

        // mathematically impossible vertex count
        if ((3 * n - s) % 2 == 1) {
            n++;
            continue;
        }

        start(g, s, n);
        n++;
    }
}