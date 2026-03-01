#include <iostream>
#include <vector>
using namespace std;

/*
Search in a rotated sorted array and return true if found, false otherwise.

Example:
Input: nums = [4,5,6,7,0,1,2],
Output: true
Target = 0
        m
4,5,6,7,8,9,0,1,2

Input: nums = [4,5,6,7,0,1,2],
Output: false
Target = 3

*/

class Solution {
   public:
    bool searchRotatedArray(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[left] < nums[mid]) {
                // Left half is sorted
                // check target is between left and mid
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[left] > nums[mid]) {
                if (target > nums[mid] && target <= nums[right]) {
                    // Right half is sorted
                    // check target is between mid and right
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                // nums[left] == nums[mid], we can't determine which half is
                // sorted just move left pointer to skip the duplicate
                left++;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << "Index of target " << target << ": "
         << sol.searchRotatedArray(nums, target) << endl;
    target = 3;
    cout << "Index of target " << target << ": "
         << sol.searchRotatedArray(nums, target) << endl;
    return 0;
}