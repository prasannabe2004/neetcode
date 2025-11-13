/*
 * Given an integer array nums, return true if any value appears at least twice
 * in the array.
 *
 * Expectation: Return true if there are duplicates, false otherwise.
 *
 * Example:
 * Input: nums = [1,2,3,1]
 * Output: true
 */

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int n : nums) {
            if (seen.count(n)) {
                return true;
            }
            seen.insert(n);
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    cout << s.hasDuplicate(nums) << endl;
    return 0;
}