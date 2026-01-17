#include <iostream>
#include <vector>

using namespace std;

/*
Find the Maximum Area of a Container
https://leetcode.com/problems/container-with-most-water
Given n non-negative integers a1, a2, ..., an , where each represents a point
at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of
the line i is at (i, ai) and (i, 0). Find two lines, which together with the
x-axis forms a container, such that the container contains the most water.
Example:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array
[1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
container can contain is 49.
*/

class Solution {
   public:
    /*
    Brute Force approach
    Time Complexity: O(N^2)
    Space Complexity: O(1)
    */
    int maxAreaBruteForce(vector<int>& heights) {
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            for (int j = i + 1; j < heights.size(); j++) {
                int area = min(heights[i], heights[j]) * (j - i);
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
    /*
    Two pointer approach
    Time Complexity: O(N)
    Space Complexity: O(1)
    */
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxArea = 0;

        while (left < right) {
            int height = min(heights[left], heights[right]);
            int width = right - left;
            int area = height * width;
            maxArea = max(maxArea, area);

            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max Area (Brute Force): " << sol.maxAreaBruteForce(heights)
         << endl;
    cout << "Max Area (Two Pointers): " << sol.maxArea(heights) << endl;
    return 0;
}