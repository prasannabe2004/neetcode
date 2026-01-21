#include <iostream>
#include <vector>
using namespace std;

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to
you beforehand. (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
Find the minimum element.
You may assume no duplicate exists in the array.
Example:
Input: [4,5,6,7,0,1,2],
Output: 0
*/

class Solution {
   public:
    int minRotatedArray(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
    int minRotatedArray2(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int minValue = nums[0];
        while (left <= right) {
            if (nums[left] < nums[right]) {
                minValue = min(minValue, nums[left]);
                break;
            }
            int mid = left + (right - left) / 2;
            minValue = min(minValue, nums[mid]);
            if (nums[mid] >= nums[left]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return minValue;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << "Minimum in Rotated Sorted Array: " << sol.minRotatedArray(nums)
         << endl;
    cout << "Minimum in Rotated Sorted Array (Method 2): "
         << sol.minRotatedArray2(nums) << endl;
    return 0;
}