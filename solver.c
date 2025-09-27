#include "nqueens.h"

// Solve the N–Queens problem recursively
bool solve_nqueens_util(int board[], int col, int n) {
    if (col >= n) {
        print_board(board, n); // Print the current solution
        return false;          // Changed from 'true' → 'false' so it doesn’t stop
    }

    for (int i = 0; i < n; i++) {
        if (is_safe(board, i, col, n)) {
            board[col] = i; // Place the queen
            solve_nqueens_util(board, col + 1, n); // Removed the "if(...) return true;"
            board[col] = -1; // Backtrack
        }
    }
    return false; // End of recursion path, keep searching
}

// Wrapper function to solve N–Queens
void solve_nqueens(int n) {
    int *board = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        board[i] = -1;

    printf("Solutions for N = %d:\n", n);
    solve_nqueens_util(board, 0, n);

    free(board);
}

