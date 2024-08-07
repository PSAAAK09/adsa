/*
PART-2
Depth First Traversal (DFT)


THEORY:-
Implement Depth First Traversal (DFT) for a graph represented by both an adjacency matrix and adjacency lists.
a) Adjacency Matrix
Description
In this representation, the graph is stored as a 2D array (matrix) where the cell at row i and column j is 1 if there is an edge from vertex i to vertex j, and 0 otherwise.

PROGRAM:-
DFT using Adjacency Matrix:


*/
#include <iostream>
#include <vector>
using namespace std;

void DFSUtil(int v, vector<vector<int>>& adjMatrix, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < adjMatrix.size(); i++) {
        if (adjMatrix[v][i] == 1 && !visited[i]) {
            DFSUtil(i, adjMatrix, visited);
        }
    }
}

void DFS(vector<vector<int>>& adjMatrix, int start) {
    vector<bool> visited(adjMatrix.size(), false);
    DFSUtil(start, adjMatrix, visited);
}

int main() {
    vector<vector<int>> adjMatrix = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    cout << "Depth First Traversal starting from vertex 0:\n";
    DFS(adjMatrix, 0);

    return 0;
}
/*
output:- 
Depth First Traversal starting from vertex 0:
0 1 3 2
*/