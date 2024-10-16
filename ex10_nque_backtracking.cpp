//EXPERMENT.NO:10
//
//Implement N-Queens Problem Using Backtracking.
//
//AIM: - To perform N-Queens Problem Using Backtracking.
//
//THEORY: 
//
//The N-Queens problem is a classic example of backtracking. The goal is to place N queens on an N×N chessboard such that no two queens threaten each other. This means no two queens can share the same row, column, or diagonal.
//Description
//The backtracking approach involves placing queens one by one in different columns, starting from the leftmost column. For each column, we try placing the queen in all rows one by one. Before placing a queen, we check for clashes with already placed queens. If a clash is found, we backtrack and try the next row. If no clash is found, we place the queen and move to the next column. This process continues until all queens are placed on the board.
//Explanation
//printSolution: This function prints the board configuration.
//isSafe: This function checks if a queen can be placed on the board at a given row and column.
//solveNQUtil: This is a recursive utility function to solve the N-Queens problem. It tries to place queens in all columns one by one.
//solveNQ: This function initializes the board and calls solveNQUtil to solve the problem.
//main: The entry point of the program which calls solveNQ.
//
//
//
//PROGRAM:-

#include <iostream>
#include <vector>
using namespace std;

#define N 8 // You can change this value to solve for different sizes of the board

void printSolution(vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<int>>& board, int row, int col) {
    // Check this row on left side
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(vector<vector<int>>& board, int col) {
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQUtil(board, col + 1))
                return true;

            board[i][col] = 0; // BACKTRACK
        }
    }

    return false;
}

bool solveNQ() {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQUtil(board, 0)) {
        cout << "Solution does not exist" << endl;
        return false;
    }

    printSolution(board);
    return true;
}

int main() {
    solveNQ();
    return 0;
}