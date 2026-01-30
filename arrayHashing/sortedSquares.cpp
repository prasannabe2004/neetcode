#include <iostream>
#include <vector>

using namespace std;

/*
You are given an integer array nums sorted in non-decreasing order, return an
array of the squares of each number sorted in non-decreasing order.

Example 1:
Input: nums = [-4,-1,0,1,2,10]
Output: [0,1,1,4,9,100]

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/
class Solution {
   public:
    /*
    Two pointer approach
    Time Complexity: O(n)
    Space Complexity: O(1)
    */
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        vector<int> result;
        while (l <= r) {
            int l_square = nums[l] * nums[l];
            int r_square = nums[r] * nums[r];
            if (l_square > r_square) {
                result.push_back(l_square);
                l++;
            } else {
                result.push_back(r_square);
                r--;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-4, -1, 0, 1, 2, 10};
    vector<int> result = s.sortedSquares(nums);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
}
