#include <iostream>
#include <vector>

using namespace std;

/*
House Robber
https://leetcode.com/problems/house-robber
You are a professional robber planning to rob houses along a street. Each house
has a certain amount of money stashed, the only constraint stopping you from
robbing each of them is that adjacent houses have security systems connected and
it will automatically contact the police if two adjacent houses were broken into
on the same night. Given an integer array nums representing the amount of money
of each house, return the maximum amount of money you can rob tonight without
alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation:
Rob house 1 (money = 1) and then rob house 3 (money = 3). Total amount you can
rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation:
Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
*/

class Solution {
   public:
    /*
    Time Complexity: O(n)
     Space Complexity: O(1)
    */
    int rob(vector<int> nums) {
        int prev1 = 0;  // Max robbed up to the previous house
        int prev2 = 0;  // Max robbed up to the house before previous

        for (int num : nums) {
            int temp = prev1;
            prev1 = max(prev2 + num, prev1);
            prev2 = temp;
        }
        return prev1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << "Maximum amount that can be robbed: " << s.rob(nums) << endl;
    return 0;
}