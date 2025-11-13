/*
 * Given a non-empty array of integers nums, every element appears twice except
 * for one. Find that single one.
 *
 * Expectation: Return the element that appears only once.
 *
 * Example:
 * Input: nums = [2,2,1]
 * Output: 1
 */

#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum ^ nums[i];
        }
        return sum;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 2, 3, 5, 5};
    int r = s.singleNumber(nums);
    cout << r << endl;
    return 0;
}