#include <iostream>
#include <vector>

using namespace std;
/*
Given a sorted array of distinct integers and a target value, return the index
if the target is found. If not, return the index where it would be if it were
inserted in order.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
*/
class Solution {
   public:
    /*
    Binary Search Approach
     Time Complexity: O(log n)
     Space Complexity: O(1)
    */
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target)
                return m;
            else if (target < nums[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 3, 5, 6};
    cout << solution.searchInsert(nums1, 5) << endl;  // Output: 2

    vector<int> nums2 = {1, 3, 5, 6};
    cout << solution.searchInsert(nums2, 2) << endl;  // Output: 1

    vector<int> nums3 = {1, 3, 5, 6};
    cout << solution.searchInsert(nums3, 7) << endl;  // Output: 4

    return 0;
}