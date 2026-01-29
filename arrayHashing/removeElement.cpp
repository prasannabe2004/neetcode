#include <iostream>
#include <vector>

using namespace std;

/*
LeetCode Problem: Remove Element
https://leetcode.com/problems/remove-element
Given an integer array nums and an integer val, remove all occurrences of val in
nums in-place. The relative order of the elements may be changed.
Since it is impossible to change the length of the array in some languages, you
must instead have the result be placed in the first part of the array nums. More
formally, if there are k elements after removing the duplicates, then the first
k elements of nums should hold the final result. It does not matter what you
leave beyond the first k elements.

Example 1:
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of
nums being 2. It does not matter what you leave beyond the returned k (hence
they are underscores).

Example 2:
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,3,0,4,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of
nums being 0, 1, 3, 0, and 4. It does not matter what you leave beyond the
returned k (hence they are underscores).
*/

class Solution {
   public:
   /*
   Time Complexity: O(n)
   Space Complexity: O(1)
   */
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    int k = solution.removeElement(nums, val);
    cout << "New length after removing element " << val << " is: " << k << endl;
    cout << "Modified array: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}