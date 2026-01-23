/*
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers such that they add up to target.
 *
 * Expectation: Return array of two indices where nums[i] + nums[j] = target.
 *
 * Example:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
   public:
    /*
    Brute Force Approach
    Time Complexity: O(n^2)
    Space Complexity: O(1)
    */
    vector<int> twoSumBruteForce(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((nums[i] + nums[j]) == target) {
                    vector<int> result{i, j};
                    return result;
                }
            }
        }
        return {};
    }
    /*
    Using Hash map Approach
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < sizeof(nums); i++) {
            int complement = target - nums[i];
            if (m.find(complement) != m.end()) {
                vector<int> result = {m[complement], i};
                return result;
            } else {
                m[nums[i]] = i;
            }
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = s.twoSum(nums, target);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    result = s.twoSumBruteForce(nums, target);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
