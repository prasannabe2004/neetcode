#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*

Given an integer array nums and an integer k, return the kth largest element in
the array. Note that it is the kth largest element in the sorted order, not the
kth distinct element.

Example 1:
Input: nums = [12, 3, 5, 7, 19], k = 2
Output: 12
Example 2:
Input: nums = [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4
Output: 4
*/
class Solution {
   public:
    /*
     Time Complexity: O(N log N)
     Space Complexity: O(1)
    */
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
    /*
    Time Complexity: O(N log K)
    Space Complexity: O(K)
    */
    int findKthLargestPriotityQ(vector<int>& nums, int k) {
        priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        for (auto n : nums) {
            minHeap.push(n);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << s.findKthLargest(nums, 3) << endl;
    cout << s.findKthLargestPriotityQ(nums, 4) << endl;
    return 0;
}