#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for (auto n : stones) {
            maxHeap.push(n);
        }

        while (maxHeap.size() > 1) {
            int first = maxHeap.top();
            maxHeap.pop();
            int second = maxHeap.top();
            maxHeap.pop();

            int delta = first - second;
            if (delta != 0) {
                maxHeap.push(delta);
            }
        }
        if (maxHeap.empty()) return 0;
        return maxHeap.top();
    }
};

int main() {
    Solution solution;
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << solution.lastStoneWeight(stones) << endl;  // Output: 1
    return 0;
}