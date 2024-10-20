//EXPERMENT.NO:12
//
//Implement Travelling Sales Person problem using Branch and Bound approach 
//
//AIM: - To perform Travelling Sales Person problem using Branch and Bound approach .
//
//THEORY: 
//The Travelling Sales Person (TSP) problem is a classic optimization problem where you are given a set of cities and the distances between every pair of cities. The goal is to find the shortest possible route that visits each city exactly once and returns to the starting city. The Branch and Bound approach is used to solve this problem by systematically exploring all possible routes and pruning branches that cannot yield a better solution than the current best.
//Explanation
//Function findMinEdge: Finds the minimum cost edge for a given node that hasn’t been visited yet.
//Function calculateLowerBound: Calculates the lower bound of the path starting from the current node by summing the minimum cost edges for all unvisited nodes.
//Function tspBranchAndBound: This is the main function that uses the Branch and Bound approach to solve the TSP problem. It recursively explores all possible routes and prunes branches that cannot yield a better solution than the current best.
//Main function: Initializes the cost matrix, sets up the visited array, and calls the tspBranchAndBound function to find the minimum cost of the tour.
//
//
//
//PROGRAM:-

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

#define N 4

// Function to find the minimum cost edge for a given node
int findMinEdge(int node, vector<vector<int>>& costMatrix, vector<bool>& visited) {
    int minCost = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (!visited[i] && costMatrix[node][i] < minCost) {
            minCost = costMatrix[node][i];
        }
    }
    return minCost;
}

// Function to calculate the lower bound of the path starting from the current node
int calculateLowerBound(vector<vector<int>>& costMatrix, vector<bool>& visited) {
    int lowerBound = 0;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            lowerBound += findMinEdge(i, costMatrix, visited);
        }
    }
    return lowerBound;
}

// Function to solve the TSP problem using Branch and Bound
void tspBranchAndBound(vector<vector<int>>& costMatrix, vector<bool>& visited, int currentNode, int currentCost, int& minCost, int level) {
    if (level == N) {
        minCost = min(minCost, currentCost + costMatrix[currentNode][0]);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i] && costMatrix[currentNode][i] != INT_MAX) {
            visited[i] = true;
            int newCost = currentCost + costMatrix[currentNode][i];
            int lowerBound = newCost + calculateLowerBound(costMatrix, visited);
            if (lowerBound < minCost) {
                tspBranchAndBound(costMatrix, visited, i, newCost, minCost, level + 1);
            }
            visited[i] = false;
        }
    }
}

int main() {
    vector<vector<int>> costMatrix = {
        {INT_MAX, 10, 15, 20},
        {10, INT_MAX, 35, 25},
        {15, 35, INT_MAX, 30},
        {20, 25, 30, INT_MAX}
    };

    vector<bool> visited(N, false);
    visited[0] = true;
    int minCost = INT_MAX;

    tspBranchAndBound(costMatrix, visited, 0, 0, minCost, 1);

    cout << "Minimum cost of the tour = " << minCost << endl;

    return 0;
}
/*output :- 
Minimum cost of the tour = 80
*/