/*EXPERMENT.NO:9

Write a program to solve 0/1 Knapsack problem Using Dynamic Programming

AIM: -   To Perform Write a program to solve 0/1 Knapsack problem Using Dynamic Programming.

THEORY: 

The 0/1 Knapsack problem is a classic optimization problem where you are given a set of items, each with a weight and a value, and a knapsack with a maximum weight capacity. The goal is to determine the maximum value that can be obtained by selecting a subset of the items such that the total weight does not exceed the knapsack’s capacity.
Program Explanation
Input Parameters:
W: Maximum weight capacity of the knapsack.
wt: A vector containing the weights of the items.
val: A vector containing the values of the items.
n: The number of items.
Dynamic Programming Table:
We use a 2D vector dp where dp[i][w] represents the maximum value that can be obtained with the first i items and a knapsack capacity of w.
Initialization:
The table dp is initialized with zeros. This represents the base case where either the number of items is zero or the capacity of the knapsack is zero, resulting in a maximum value of zero.
Filling the Table:
We iterate through each item and each possible weight capacity.
For each item i and weight w:
If the weight of the current item wt[i-1] is less than or equal to w, we have two choices
Include the item: The value is val[i-1] plus the maximum value obtained with the remaining capacity w - wt[i-1].
Exclude the item: The value is the maximum value obtained without including the current item.
We take the maximum of these two choices and store it in dp[i][w].
If the weight of the current item is greater than w, we cannot include the item, so the value remains the same as without the item.
Result:
The value in dp[n][W] represents the maximum value that can be obtained with the given items and knapsack capacity.

*/
#include <iostream>
#include <vector>
using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapSack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main() {
    int W = 50; // Maximum weight of knapsack
    vector<int> wt = {10, 20, 30}; // Weights of items
    vector<int> val = {60, 100, 120}; // Values of items
    int n = wt.size(); // Number of items

    cout << "Maximum value in Knapsack = " << knapSack(W, wt, val, n) << endl;

    return 0;
}