#include <iostream>
#include <vector>

using namespace std;

/*
Find the Minimum in a Rotated Sorted Array
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
Suppose an array of length n sorted in ascending order is rotated between 1 and
n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
- [4,5,6,7,0,1,2] if it was rotated 4 times.
- [0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in
the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]]. Given the sorted rotated
array nums of unique elements, return the minimum element of this array. You
must write an algorithm that runs in O(log n) time. Example 1: Input: nums =
[3,4,5,1,2] Output: 1 Example 2: Input: nums = [4,5,6,7,0,1,2] Output: 0 Example
3: Input: nums = [11,13,15,17] Output: 11
*/

class Solution {
   public:
    /*
    Binary Search approach
    Time Complexity: O(log n)
    Space Complexity: O(1)
    */
    int findMin(vector<int>& nums) {
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
};

int main() {
    Solution s;
    vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << "Minimum in [3,4,5,1,2]: " << s.findMin(nums1) << endl;

    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Minimum in [4,5,6,7,0,1,2]: " << s.findMin(nums2) << endl;

    vector<int> nums3 = {11, 13, 15, 17};
    cout << "Minimum in [11,13,15,17]: " << s.findMin(nums3) << endl;

    return 0;
}