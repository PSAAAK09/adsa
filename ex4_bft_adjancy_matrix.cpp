/*Implement BFT and DFT for given graph, when graph is represented by
a) Adjacency Matrix           b) Adjacency Lists

AIM: - To perform BFT and DFT for given graph, when graph is represented by
a) Adjacency Matrix           b) Adjacency Lists

THEORY:-
Let’s implement Breadth-First Traversal (BFT) and Depth-First Traversal (DFT) for a given graph using both adjacency matrix and adjacency lists representations in C++.
PART-1

PROGRAM: 
BFT using Adjacency Matrix:
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Function to perform Breadth-First Traversal on a graph represented using adjacency matrix
void bfsMatrix(vector<vector<int>>& adjMatrix, int startNode, vector<bool>& visited) {
    queue<int> q;
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        for (int neighbor = 0; neighbor < adjMatrix.size(); ++neighbor) {
            if (adjMatrix[currentNode][neighbor] && !visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int vertices = 5; // Number of vertices in the graph
    vector<vector<int>> adjMatrix(vertices, vector<int>(vertices, 0)); // Initialize adjacency matrix

    // Add edges to the graph (modify as needed)
    adjMatrix[0][1] = adjMatrix[1][0] = 1;
    adjMatrix[0][2] = adjMatrix[2][0] = 1;
    adjMatrix[1][2] = adjMatrix[2][1] = 1;
    adjMatrix[2][3] = adjMatrix[3][2] = 1;

    vector<bool> visited(vertices, false);

    cout << "BFT using adjacency matrix (starting from vertex 0): ";
    bfsMatrix(adjMatrix, 0, visited);
    cout << endl;

    return 0;
}
/*
output:- 
BFT using adjacency matrix (starting from vertex 0): 0 1 2 3
*/