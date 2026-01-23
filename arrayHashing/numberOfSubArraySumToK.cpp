#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
/*
LeetCode Problem: Subarray Sum Equals K
https://leetcode.com/problems/subarray-sum-equals-k
Given an array of integers nums and an integer k, return the total number of
subarrays whose sum equals to k.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2
Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
Example 3:
Input: nums = [1,2,1,2,1], k = 3
Output: 4
*/

class Solution {
   public:
    /*
     Brute force approach
     Time Complexity: O(N^2)
     Space Complexity: O(1)
     */
    int subarraySumBruteForce(vector<int>& nums, int k) {
        int totSubArray = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == k) totSubArray++;
            }
        }
        return totSubArray;
    }
    /*
     Prefix sum approach
     Time Complexity: O(N^2)
     Space Complexity: O(N)
     */
    int subarraySumPrefix(vector<int>& nums, int k) {
        int totSubArray = 0;
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (prefixSum[j] - prefixSum[i] == k) {
                    totSubArray++;
                }
            }
        }
        return totSubArray;
    }
    /*
     Optimized Prefix sum approach using hashmap
     Time Complexity: O(N)
     Space Complexity: O(N)
     */
    int subarraySum(vector<int>& nums, int k) {
        int totSubArray = 0;
        int n = nums.size();
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;  // Base case: one way to have sum 0
        int currentPrefixSum = 0;
        for (int i = 0; i < n; i++) {
            currentPrefixSum += nums[i];
            int complement = currentPrefixSum - k;
            if (prefixSumCount.find(complement) != prefixSumCount.end()) {
                totSubArray += prefixSumCount[complement];
            }
            prefixSumCount[currentPrefixSum]++;
        }
        return totSubArray;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1, 2, 1};
    int k = 3;
    cout << "Total Subarrays with sum equal to " << k << ": "
         << sol.subarraySum(nums, k) << endl;
    return 0;
}