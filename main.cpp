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
void make_edge(const int from, const int to, vector<vector<int>>* v) {
    assert(v->at(from).size() < 3);

    v->at(from).push_back(to);
    if (to != SEMIEDGE) {
        v->at(to).push_back(from);
    }
}

// removes the edge last added to from in v
// s points to number of semi-edges
int undo_edge(const int from, vector<vector<int>>* v) {
    int to = v->at(from).back();
    v->at(from).pop_back();

    if (to != SEMIEDGE) {
        v->at(to).pop_back();
    }

    return to;
}

/** recursively attempts to add edges in a graph of set size,
 * incrementally generating every possible (3,g,s)-multipole of size N
 *
 * G - target minimum girth
 * N - total number of vertices
 * p - current target vertex
 * min_next - minimum vertex that p could have edge to (helper variable to counteract some isomorphism)
 * v - adjacency list
 */
void recursion(const int G, const int N, int p, int min_next, vector<vector<int>>* v) {
    // finds next free stub
    // if none exists, checks success, then returns
    while (v->at(p).size() == 3) {
        p++;
        min_next = p + 1;
        if (p == N) {
            cout << "Graph found:" << endl;
            print_graph(v);
            return;
        }
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

            make_edge(p, next, v);
            if (check_girth(p, G, v)) {
                recursion(G, N, p, next, v);
            }
            undo_edge(p, v);

            // if the destination vertex was otherwise completely unused, the cycle will stop
            // (as every vertex after this one is topologically the same and would result in isomorphic graphs)
            if (v->at(next).size() == 0) {
                break;
            }
        }

        next++;
    }
}

void assign_semiedges(const int G, const int N, int s, int p, vector<vector<int>>* v) {
    if (p == N) {
        return;
    }

    // adds a semi-edge
    make_edge(p, SEMIEDGE, v);
    s--;

    if (s == 0) {
        //cout << "Calling recursion on: " << endl;
        //print_graph(v);
        recursion(G, N, 0, 1, v);
        undo_edge(p, v);
        return;
    }

    // recursive branch for adding another semi-edge to the same vertex
    // semi-edge counts for vertices are in descending order. Vertex cannot have more semi-edges than predecessor.
    if (v->at(p).size() < 3) {
        if (p == 0) {
            assign_semiedges(G, N, s, p, v);
        } else {
             if (v->at(p - 1).size() > v->at(p).size()) {
                 assign_semiedges(G, N, s, p, v);
             }
        }
    }

    // recursive branch for not adding another semi-edge to the same vertex
    // (only if the current one has at least one, so that they are all in sequence, next to each other)
    if (v->at(p).size() > 0) {
        assign_semiedges(G, N, s, p + 1, v);
    }

    // removing
    undo_edge(p, v);
}

// initializes recursion for searching for multipoles with the characteristics:
// girth G
// S semi-edges
// N total vertices
void start (const int G, const int S, const int N) {
    vector<vector<int>> v(N);               // adjacency list

    for (int i = 0; i < N; i++) {
        v.at(i).reserve(3);
    }

    if (S == 0) {
        recursion(G, N, 0, 1, &v);
    } else {
        assign_semiedges(G, N, S, 0, &v);
    }
}

// driver code
int main() {
    int g, s;

    cin >> g >> s;

    int n = 1;
    while (n <= 10) {
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