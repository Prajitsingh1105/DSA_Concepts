#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int val) {
    // row & column check
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == val) return false;
        if (board[i][col] == val) return false;
    }

    // 3x3 box check
    int startRow = 3 * (row / 3);
    int startCol = 3 * (col / 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == val)
                return false;
        }
    }

    return true;
}

bool solve(vector<vector<int>> &board) {
    int n = 9;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {

            if (board[row][col] == 0) {

                for (int val = 1; val <= 9; val++) {

                    if (isSafe(row, col, board, val)) {
                        board[row][col] = val;

                        if (solve(board))
                            return true;

                        // backtrack
                        board[row][col] = 0;
                    }
                }

                return false;
            }
        }
    }

    return true;
}

void solveSudoku(vector<vector<int>> &sudoku) {
    solve(sudoku);
}

int main() {
    vector<vector<int>> sudoku = {
        {0,2,0,9,3,0,4,0,6},
        {0,7,3,0,4,0,5,2,8},
        {4,0,0,8,2,0,0,3,0},
        {3,0,0,0,0,0,0,5,7},
        {0,0,0,3,0,0,8,6,4},
        {7,8,6,4,0,0,0,1,2},
        {0,9,4,5,0,1,7,0,3},
        {6,3,1,7,8,4,0,9,0},
        {8,5,0,0,0,3,6,4,0}
    };

    solveSudoku(sudoku);

    cout << "Solution:\n";
    for (auto &row : sudoku) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}