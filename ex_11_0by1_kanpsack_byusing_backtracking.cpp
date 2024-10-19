//EXPERMENT.NO:11
//
//Use Backtracking strategy to solve 0/1 Knapsack problem.
//
//AIM: - To perform to solve 0/1 Knapsack problem Use Backtracking strategy.
//
//THEORY: 
//
//The 0/1 Knapsack problem is a classic optimization problem where you are given a set of items, each with a weight and a value, and a knapsack with a maximum weight capacity. The goal is to determine the maximum value that can be obtained by selecting a subset of the items such that the total weight does not exceed the knapsack’s capacity. In the 0/1 Knapsack problem, each item can either be included in the knapsack or excluded (hence the name 0/1).
//
//The backtracking approach involves exploring all possible subsets of items and keeping track of the maximum value obtained without exceeding the weight capacity. This approach is not the most efficient but is useful for understanding the problem and learning about backtracking techniques.
//Explanation
//Function max: A utility function to return the maximum of two integers.
//Function knapsack: This function uses recursion to solve the 0/1 Knapsack problem. It takes the remaining capacity W, the list of weights and values, and the number of items n as input.
//If there are no items left or the remaining capacity is zero, it returns 0.
//If the weight of the nth item is more than the remaining capacity, it skips the item.
//Otherwise, it returns the maximum value obtained by either including or excluding the nth item.
//Main function: Initializes the values and weights of the items, the maximum capacity of the knapsack, and calls the knapsack function to find the maximum value that can be obtained.
//
//PROGRAM:-
#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem using backtracking
int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    // Base case: no items left or no remaining capacity
    if (n == 0 || W == 0) {
        return 0;
    }

    // If the weight of the nth item is more than the remaining capacity, skip it
    if (weights[n - 1] > W) {
        return knapsack(W, weights, values, n - 1);
    } else {
        // Return the maximum of two cases:
        // 1. nth item included
        // 2. nth item not included
        return max(
            values[n - 1] + knapsack(W - weights[n - 1], weights, values, n - 1),
            knapsack(W, weights, values, n - 1)
        );
    }
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50;
    int n = values.size();

    cout << "Maximum value in Knapsack = " << knapsack(W, weights, values, n) << endl;

    return 0;
}