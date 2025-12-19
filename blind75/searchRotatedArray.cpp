#include <iostream>
#include <vector>
using namespace std;

/*
Search in a rotated sorted array and return its index. If not found, return -1.
Example:
Input: nums = [4,5,6,7,0,1,2],
Output: 4
Target = 0
*/

class Solution {
   public:
    int searchRotatedArray(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[left] <= nums[mid]) {
                if (target > nums[mid] or target < nums[left]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                if (target < nums[mid] or target > nums[right]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
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