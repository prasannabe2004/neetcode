#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:
Input: nums = []
Output: []
Example 3:
Input: nums = [0]
Output: []
*/
class Solution {
   public:
    /*
    Time Complexity: O(n^2)
     Space Complexity: O(n)
    */
    vector<vector<int>> threeSumUsingHashmap(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            unordered_set<int> seen;
            for (int j = i + 1; j < n; j++) {
                int complement = -nums[i] - nums[j];
                if (seen.count(complement)) {
                    res.push_back({nums[i], complement, nums[j]});
                    while (j + 1 < n && nums[j] == nums[j + 1]) j++;
                }
                seen.insert(nums[j]);
            }
        }
        return res;
    }
    /*
     Time Complexity: O(n^3)
     Space Complexity: O(1)
    */
    vector<vector<int>> threeSumBruteForce(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        if (find(res.begin(), res.end(), triplet) ==
                            res.end()) {
                            res.push_back(triplet);
                        }
                    }
                }
            }
        }
        return res;
    }
    /*
    Time Complexity: O(n^2)
    Space Complexity: O(1)
    */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int t = nums[i] + nums[l] + nums[r];
                if (t == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    r--;
                    l++;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                } else if (t > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = sol.threeSum(nums);

    for (const auto& triplet : result) {
        cout << "[";
        for (const auto& num : triplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    result = sol.threeSumBruteForce(nums);
    cout << "Brute Force Results:" << endl;
    for (const auto& triplet : result) {
        cout << "[";
        for (const auto& num : triplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    result = sol.threeSumUsingHashmap(nums);
    cout << "Hashmap Results:" << endl;
    for (const auto& triplet : result) {
        cout << "[";
        for (const auto& num : triplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
