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

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    /* Implementation of duplicate checking using hash set
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
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
    /* Implementation of duplicate checking using sorting
    Time Complexity: O(n log n)
    Space Complexity: O(1) or O(n) depending on sorting algorithm
    */
    bool hasDuplicateSorting(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3, 1};
    cout << s.hasDuplicate(nums) << endl;
    cout << s.hasDuplicateSorting(nums) << endl;
    return 0;
}