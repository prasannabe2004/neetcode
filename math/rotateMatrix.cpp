#include <iostream>
#include <vector>

using namespace std;

/*
You are given an n x n 2D matrix representing an image, rotate the image by
90 degrees (clockwise). You have to rotate the image in-place, which means you
have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix
and do the rotation.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
Constraints:
n == matrix.length == matrix[i].length 1 <= n <= 20-1000 <= matrix[i][j] <= 1000
*/

class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix.size() - 1;
        while (left < right) {
            for (int i = 0; i < right - left; i++) {
                int top = left;
                int bottom = right;

                // Save the top-left value
                int topLeft = matrix[top][left + i];

                // Move bottom-left to top-left
                matrix[top][left + i] = matrix[bottom - i][left];

                // Move bottom-right to bottom-left
                matrix[bottom - i][left] = matrix[bottom][right - i];

                // Move top-right to bottom-right
                matrix[bottom][right - i] = matrix[top + i][right];

                // Move top-left to top-right
                matrix[top + i][right] = topLeft;
            }
            left++;
            right--;
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    sol.rotate(matrix1);
    cout << "Rotated Matrix 1:" << endl;
    for (const auto& row : matrix1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    vector<vector<int>> matrix2 = {
        {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    sol.rotate(matrix2);
    cout << "Rotated Matrix 2:" << endl;
    for (const auto& row : matrix2) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}