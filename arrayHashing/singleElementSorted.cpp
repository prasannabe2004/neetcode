#include <iostream>

using namespace std;

/*
Single Element in a Sorted Array
https://leetcode.com/problems/single-element-in-a-sorted-array
You are given a sorted array consisting of only integers where every element
appears exactly twice, except for one element which appears exactly once. Find
this single element that appears only once.

Example 1:
Input: nums = [1,1,2,3,3,4,4,5,5]
Output: 2
Explanation: 2 is the only element that appears once.

Example 2:
Input: nums = [0,0,1,1,2]
Output: 2
Explanation: 2 is the only element that appears once.

Constraints:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/

class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            cout << "low: " << low << ", mid: " << mid << ", high: " << high
                 << endl;
            if (mid % 2 == 1) {
                mid--;
            }
            if (nums[mid] != nums[mid + 1]) {
                high = mid;
            } else {
                low = mid + 2;
            }
        }
        return nums[low];
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 5, 5};
    cout << "Single element in [1, 1, 2, 3, 3, 4, 4, 5, 5]: "
         << s.singleNonDuplicate(nums) << endl;

    nums = {0, 0, 1, 1, 2};
    cout << "Single element in [0, 0, 1, 1, 2]: " << s.singleNonDuplicate(nums)
         << endl;

    return 0;
}