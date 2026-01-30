#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/*
You are given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

Example 1:
Input: nums = [1,7,3,6,5,6] 
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

Example 2:
Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.

*/
class Solution {
   public:
   /*
   Time Complexity: O(n)
   Space complexity: O(1)
   */
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        for (auto i : nums) totalSum += i;
        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int rightSum = totalSum - leftSum - nums[i];
            if (leftSum == rightSum)
                return i;
            else {
                leftSum += nums[i];
            }
        }
        return -1;
    }
    /*
    Brute force approach
    Time Complexity: O(n^2)
    Space complexity: O(1)
    */
    int pivotIndexBruteForce(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int leftSum = 0;
            int rightSum = 0;
            for (int j = 0; j < i; j++) {
                leftSum += nums[j];
            }
            for (int k = i + 1; k < nums.size(); k++) {
                rightSum += nums[k];
            }
            if (leftSum == rightSum) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> test = {-1, -1, 0, 1, 1, 0};
    cout << s.pivotIndex(test) << endl;
    cout << s.pivotIndexBruteForce(test) << endl;
    return 0;
}
