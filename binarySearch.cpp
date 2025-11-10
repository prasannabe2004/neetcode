#include <iostream>
#include <vector>
using namespace std;

/*
Binary Search Problem:
Given a sorted array of integers nums and an integer target, search for the target
in the array. If the target exists, return its index. Otherwise, return -1.

The array must be sorted in ascending order.

Solution Approach:
Classic binary search implementation:
- Maintain two pointers: left (start) and right (end) of the search range
- Calculate middle index: mid = left + (right - left) / 2 (avoids overflow)
- Compare nums[mid] with target:
  - If nums[mid] < target: search in right half (left = mid + 1)
  - If nums[mid] > target: search in left half (right = mid - 1)
  - If nums[mid] == target: found, return mid
- If not found after loop, return -1

Time Complexity: O(log n) - halves the search space in each iteration
Space Complexity: O(1) - only uses a constant amount of extra space

Example:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4 (9 is at index 4 in the array)
*/

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left <= right)
        {
            mid = left + ((right - left) / 2);
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    cout << s.search(nums, target) << endl;
    return 0;
}
