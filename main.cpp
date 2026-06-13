#include <cassert>
#include <deque>
#include <iostream>
#include <limits.h>
#include <unordered_set>
#include <vector>

#define SEMIEDGE (-1)

using namespace std;

// check if graph satisfies girth constraints by doing BFS from source node
// TODO: remember to cite source for this (graph girth algorithm)
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

// debug function
void print_graph(vector<vector<int>>* v) {
    for (int i = 0; i < v->size(); i++) {
        cout << i << ": ";
        for (int c : v->at(i)) {
            cout << c << " ";
        }
        cout << endl;
    }
}

void make_edge(int from, int to, vector<vector<int>>* v, vector<int>* d, int* s) {
    assert(d->at(from) < 3);
    assert(v->at(from).size() < 3);

    v->at(from).push_back(to);
    d->at(from)++;

    if (to == SEMIEDGE) {
        (*s)--;
        assert(*s >= 0);
    } else {
        v->at(to).push_back(from);
        d->at(to)++;
    }
}

int undo_edge(int from, vector<vector<int>>* v, vector<int>* d, int* s) {
    assert(d->at(from) > 0);
    assert(d->at(from) > 0);

    int to = v->at(from).back();
    v->at(from).pop_back();
    d->at(from)--;

    if (to == SEMIEDGE) {
        (*s)++;
    } else {
        v->at(to).pop_back();
        d->at(to)--;
    }

    return to;
}

void recursion(const int G, const int N, int s, int p, int min_next, vector<vector<int>>* v, vector<int>* d) {
    while (d->at(p) == 3) {
        p++;
        min_next = p + 1;
        if (p == N) {
            if (s == 0) {
                cout << "Success" << endl;
                print_graph(v);
            }
            return;
        }
    }

    //int next = p + 1;
    int next = min_next;

    while (next < N) {

        if (!v->at(p).empty()) {
            if (v->at(p).back() == next) {
                next++;
                continue;
            }
        }

        if (d->at(next) < 3) {

            // the key here is that since no illegal cycles existed before the addition of the edge
            // any newly formed illegal cycles must include the source vertex
            make_edge(p, next, v, d, &s);
            if (check_girth(p, G, v)) {
                recursion(G, N, s, p, next + 1, v, d);
            }
            undo_edge(p, v, d, &s);

            // vertex was added - after this it would just make isomorphic graphs
            if (d->at(next) == 0) {
                break;
            }
        }

        next++;
    }

    if (s > 0) {

        // semi-edge optimization - only adds semi-edges if vertex has no other outgoing edges yet
        if (!v->at(p).empty()) {
            if (v->at(p).back() > p) {
                return;
            }
        }

        make_edge(p, SEMIEDGE, v, d, &s);
        recursion(G, N, s, p, next, v, d);
        undo_edge(p, v, d, &s);
    }
}


// initializes recursion for searching for multipoles with the characteristics:
// girth G
// S semi-edges
// N total vertices
void start (const int G, const int S, const int N) {
    int s = 0;                              // current number of semi-edges
    vector<vector<int>> v(N);               // adjacency list, only contains u->v for u < v
    vector<int> d(N, 0);               // degrees of vertices

    for (int i = 0; i < N; i++) {
        v.at(i).reserve(3);
    }

    recursion(G, N, S, 0, 1, &v, &d);
}


int main() {
    int g, s;

    cin >> g >> s;

    int n = 1;
    while (true) {
        cout << "STARTING SEARCH: N = " << n << endl;
        start(g, s, n);
        n++;

        if (n == 10) {break;}
    }
}