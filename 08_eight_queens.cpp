#include <iostream>
using namespace std;

#define N 8

void printBoard(int queens[]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (queens[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void solveNQueens(int row, int queens[], bool col[], bool mainDiag[], bool antiDiag[]) {
    if (row == N) {
        printBoard(queens);
        return;
    }

    for (int c = 0; c < N; c++) {
        // Check if placing a queen at (row, c) is safe
        if (!col[c] && !mainDiag[row - c + N - 1] && !antiDiag[row + c]) {
            queens[row] = c;                // Place queen
            col[c] = mainDiag[row - c + N - 1] = antiDiag[row + c] = true;

            solveNQueens(row + 1, queens, col, mainDiag, antiDiag);

            // Backtrack
            col[c] = mainDiag[row - c + N - 1] = antiDiag[row + c] = false;
        }
    }
}

int main() {
    int queens[N] = {0};                   // Stores column position of queens for each row
    bool col[N] = {false};                 // Tracks used columns
    bool mainDiag[2 * N - 1] = {false};    // Tracks main diagonals
    bool antiDiag[2 * N - 1] = {false};    // Tracks anti-diagonals

    solveNQueens(0, queens, col, mainDiag, antiDiag);

    return 0;
}
