#include <iostream>
#include <vector>

using namespace std;

/*
Island Perimeter
https://leetcode.com/problems/island-perimeter
You are given row x col grid representing a map where grid[i][j] = 1 represents
land and grid[i][j] = 0 represents water. Grid cells are connected
horizontally/vertically (not diagonally). The grid is completely surrounded by
water, and there is exactly one island (i.e., one or more connected land cells).
The island doesn't have

"lakes" (water inside that isn't connected to the water around the island). One
cell is a square with side length 1. The grid is rectangular, width and height
don't exceed 100. Determine the perimeter of the island.

Example 1:
Input: grid = [[0,1,0,0],
               [1,1,1,0],
               [0,1,0,0],
               [1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.

Example 2:
Input: grid = [[1]]
Output: 4
Explanation: The perimeter of the island is 4.

Example 3:
Input: grid = [[1,0]]
Output: 4
Explanation: The perimeter of the island is 4.
*/

class Solution {
   public:
    /*
    Brute Force Approach:
    Time Complexity: O(m*n) where m is the number of rows and n is the number of
    columns in the grid
    Space Complexity: O(1)
    */
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    perimeter += 4;

                    // Check the upper cell
                    if (i > 0 && grid[i - 1][j] == 1) {
                        perimeter -= 2;
                    }
                    // Check the left cell
                    if (j > 0 && grid[i][j - 1] == 1) {
                        perimeter -= 2;
                    }
                }
            }
        }
        return perimeter;
    }
    /*
    DFS Approach:
    Time Complexity: O(m*n) where m is the number of rows and n is the number of
    columns in the grid
    Space Complexity: O(m*n) in the worst case when the grid
    is filled with land
    */
    vector<vector<bool>> visited;
    int islandPerimeterDFS(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        visited.resize(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    return dfs(grid, i, j);
                }
            }
        }
        return 0;
    }
    int dfs(vector<vector<int>>& grid, int i, int j) {
        // Check for out of bounds or water
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] == 0) {
            return 1;  // Contributes to perimeter
        }
        if (grid[i][j] == -1) {
            return 0;  // Already visited land
        }
        grid[i][j] = -1;  // Mark as visited
        int perimeter = 0;
        perimeter += dfs(grid, i - 1, j);  // Up
        perimeter += dfs(grid, i + 1, j);  // Down
        perimeter += dfs(grid, i, j - 1);  // Left
        perimeter += dfs(grid, i, j + 1);  // Right
        return perimeter;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid1 = {
        {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    cout << "Perimeter of the island in grid1: " << s.islandPerimeterDFS(grid1)
         << endl;

    vector<vector<int>> grid2 = {{1}};
    cout << "Perimeter of the island in grid2: " << s.islandPerimeterDFS(grid2)
         << endl;

    vector<vector<int>> grid3 = {{1, 0}};
    cout << "Perimeter of the island in grid3: " << s.islandPerimeterDFS(grid3)
         << endl;

    return 0;
}