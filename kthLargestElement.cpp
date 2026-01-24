#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        for (auto n : nums) {
            minHeap.push(n);
        }
        return minHeap.pop();
    }
};