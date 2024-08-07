/*Implement BFT and DFT for given graph, when graph is represented by
a) Adjacency Matrix           b) Adjacency Lists

AIM: - To perform BFT and DFT for given graph, when graph is represented by
a) Adjacency Matrix           b) Adjacency Lists

THEORY:-
Let’s implement Breadth-First Traversal (BFT) and Depth-First Traversal (DFT) for a given graph using both adjacency matrix and adjacency lists representations in C++.
PART-1

PROGRAM: 
BFT using Adjacency Lists:
*/
#include <iostream>
#include <vector>
using namespace std;

// Function to perform Breadth-First Traversal on a graph represented using adjacency lists
void bfsList(vector<vector<int>>& adjList, int startNode, vector<bool>& visited) {
    queue <int> q;
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int vertices = 5; // Number of vertices in the graph
    vector<vector<int>> adjList(vertices);

    // Add edges to the graph (modify as needed)
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(2);
    adjList[2].push_back(3);

    vector<bool> visited(vertices, false);

    cout << "BFT using adjacency lists (starting from vertex 0): ";
    bfsList(adjList, 0, visited);
    cout << endl;
  return 0;
}

