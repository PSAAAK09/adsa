/*
EXPERMENT.NO:5

Write a program for finding the biconnected components in a given graph.

AIM: - To perform for finding the biconnected components in a given graph.

THEORY:-
This program uses DFS to find and print the biconnected components of a graph. The BCCUtil function is a utility function that performs the DFS traversal and identifies the biconnected components.

PROGRAM:-
*/

#include <iostream>
#include <list>
#include <stack>
#define NIL -1

using namespace std;

class Edge {
public:
    int u, v;
    Edge(int u, int v) : u(u), v(v) {}
};

class Graph {
    int V, E;
    list<int> *adj;
    void BCCUtil(int u, int disc[], int low[], list<Edge> *st, int parent[]);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void BCC();
};

Graph::Graph(int V) {
    this->V = V;
    this->E = 0;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
    E++;
}

void Graph::BCCUtil(int u, int disc[], int low[], list<Edge> *st, int parent[]) {
    static int time = 0;
    disc[u] = low[u] = ++time;
    int children = 0;

    for (auto v : adj[u]) {
        if (disc[v] == NIL) {
            children++;
            parent[v] = u;
            st->push_back(Edge(u, v));
            BCCUtil(v, disc, low, st, parent);
            low[u] = min(low[u], low[v]);

            if ((disc[u] == 1 && children > 1) || (disc[u] > 1 && low[v] >= disc[u])) {
                while (st->back().u != u || st->back().v != v) {
                    cout << st->back().u << "--" << st->back().v << " ";
                    st->pop_back();
                }
                cout << st->back().u << "--" << st->back().v << endl;
                st->pop_back();
            }
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
            if (disc[v] < disc[u]) {
                st->push_back(Edge(u, v));
            }
        }
    }
}

void Graph::BCC() {
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
    list<Edge> *st = new list<Edge>[E];

    for (int i = 0; i < V; i++) {
        disc[i] = NIL;
        low[i] = NIL;
        parent[i] = NIL;
    }

    for (int i = 0; i < V; i++) {
        if (disc[i] == NIL) {
            BCCUtil(i, disc, low, st, parent);
            while (!st->empty()) {
                cout << st->back().u << "--" << st->back().v << " ";
                st->pop_back();
            }
            cout << endl;
        }
    }
}

int main() {
    Graph g(12);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(1, 5);
    g.addEdge(0, 6);
    g.addEdge(5, 6);
    g.addEdge(5, 7);
    g.addEdge(5, 8);
    g.addEdge(7, 8);
    g.addEdge(8, 9);
    g.addEdge(10, 11);

    g.BCC();

    return 0;
}
/*
output:-
4--2 3--4 3--1 2--3 1--2
8--9
8--5 7--8 5--7
6--0 5--6 1--5 0--1
10--11

 
*/