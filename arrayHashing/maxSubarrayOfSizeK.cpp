#include <iostream>
#include <vector>
using namespace std;

/*
Given an array of integers arr[] and an integer k, find the maximum possible sum
among all contiguous subarrays of size exactly k. A subarray is a sequence of
consecutive elements from the original array. Return the maximum sum that can be
obtained from any such subarray of length k.

Examples:

Input  : arr[] = [100, 200, 300, 400],  k = 2
Output : 700
Explanation: We get maximum sum by adding subarray [300,400] of size 2

Input  : arr[] = [1, 4, 2, 10, 23, 3, 1, 0, 20], k = 4
Output : 39
Explanation: We get maximum sum by adding subarray [4, 2, 10, 23] of size 4.

Input  : arr[] = [2, 3], k = 1
Output : 3
Explanation: The subarrays of size 1 are [2] and [3]. The maximum sum is 3.
*/
class Solution {
   public:
    /*
    Brute Force
    Time Complexity: O(n^2)
    Space Complexity: O(1)
    */
    int maxSubArrayOfSizeK(vector<int>& nums, int k) {
        int maxSum = 0;
        for (int i = 0; i < nums.size() - k; i++) {
            int currentSum = 0;
            for (int j = 0; j < k; j++) {
                currentSum += nums[i + j];
            }
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
    /*
    Using Prefix sum
    Time Complexity: O(n)
    Space Complexity: O(1)
    */
    int maxSubArrayOfSizeKPrefixSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        // build prefix sum array
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int maxSum = 0;

        // compute sum of each subarray of size k
        // using prefix array
        for (int i = 0; i <= n - k; i++) {
            int j = i + k - 1;
            int currSum = prefix[j + 1] - prefix[i];

            // update maximum sum
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k = 4;
    cout << "Maximum Subarray Sum brute force: "
         << sol.maxSubArrayOfSizeK(nums, k) << endl;
    cout << "Maximum Subarray Sum prefix sum: "
         << sol.maxSubArrayOfSizeKPrefixSum(nums, k) << endl;
    return 0;
}