#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isValidSudoku1(vector<vector<char>>& board) {
        unordered_set<char> row[9], col[9], box[9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int boxIndex = (i / 3) * 3 + j / 3;
                if (board[i][j] == '.') continue;
                if (row[i].count(board[i][j]) || col[j].count(board[i][j]) ||
                    box[boxIndex].count(board[i][j])) {
                    return false;
                }
                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                box[boxIndex].insert(board[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            unordered_set<char> seen;
            for (int i = 0; i < 9; i++) {
                if (board[row][i] == '.') continue;
                if (seen.count(board[row][i])) {
                    return false;
                }
                seen.insert(board[row][i]);
            }
        }
        for (int col = 0; col < 9; col++) {
            unordered_set<char> seen;
            for (int i = 0; i < 9; i++) {
                if (board[i][col] == '.') continue;
                if (seen.count(board[i][col])) {
                    return false;
                }
                seen.insert(board[i][col]);
            }
        }
        for (int square = 0; square < 9; square++) {
            unordered_set<char> seen;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if (board[row][col] == '.') continue;
                    if (seen.count(board[row][col])) {
                        return false;
                    }
                    seen.insert(board[row][col]);
                }
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << "Is the Sudoku board valid? \n"
         << (solution.isValidSudoku(board) ? "Yes" : "No") << endl;
    return 0;
}