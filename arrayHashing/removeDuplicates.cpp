#include <iostream>

using namespace std;

/*
Problem:
Given an integer array nums sorted in non-decreasing order, remove the
duplicates in-place such that each unique element appears only once. The
relative order of the elements should be kept the same. Then return the number
of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you
need to do the following things:

Change the array nums such that the first k elements of nums contain the unique
elements in the order they were present in nums initially. The remaining
elements of nums are not important as well as the size of nums. Return k.

Example:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]

*/
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int left = 1;

        for (int right = 1; right < nums.size(); right++) {
            if (nums[right - 1] != nums[right]) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2};
    int k = sol.removeDuplicates(nums);
    cout << k << endl;
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}