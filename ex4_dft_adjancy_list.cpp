/*
b) Adjacency Lists

THEORY:-

In this representation, the graph is stored as an array of lists. Each list at index i contains the vertices adjacent to vertex i.

PROGRAM:-
*/
#include <iostream>
#include <list>
#include <vector>
using namespace std;

void DFSUtil(int v, vector<list<int>>& adjList, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int adj : adjList[v]) {
        if (!visited[adj]) {
            DFSUtil(adj, adjList, visited);
        }
    }
}

void DFS(vector<list<int>>& adjList, int start) {
    vector<bool> visited(adjList.size(), false);
    DFSUtil(start, adjList, visited);
}

int main() {
    vector<list<int>> adjList(4);
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(0);
    adjList[1].push_back(3);
    adjList[2].push_back(0);
    adjList[2].push_back(3);
    adjList[3].push_back(1);
    adjList[3].push_back(2);

    cout << "Depth First Traversal starting from vertex 0:\n";
    DFS(adjList, 0);

    return 0;
}
/*
output:- 
Depth First Traversal starting from vertex 0:
0 1 3 2
--------------------------------
*/
