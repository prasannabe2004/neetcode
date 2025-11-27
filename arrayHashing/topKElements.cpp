#include <iostream>

using namespace std;

/*
Given an integer array nums and an integer k, return the k most frequent
elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

*/
class Solution {
   public:
    /*
    Using sorting
    Time Complexity: O(nlogn)
    Space Complexity: O(n)
    */
    vector<int> topKFrequent2(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        vector<pair<int, int>> arr;
        for (const auto& p : count) {
            arr.push_back({p.second, p.first});
        }
        sort(arr.rbegin(), arr.rend());

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(arr[i].second);
        }
        return res;
    }
    /*
    Using Heap
    Time Complexity: O(nlogk)
    Space Complexity: O(n)
    */
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        priority_queue<pair<int, int>> pq;
        for (const auto& p : count) {
            pq.push({p.second, p.first});
        }

        vector<int> res;
        while (k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
    /*
    Using Bucket Sort
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
    vector<int> topKFrequent1(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        vector<vector<int>> freq(nums.size() + 1);

        for (auto n : nums) {
            map[n] = map[n] + 1;
        }

        for (auto entry : map) freq[entry.second].push_back(entry.first);

        vector<int> res;
        for (int i = freq.size() - 1; i > 0; i--) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 5, 5};
    int k = 2;
    vector<int> res = s.topKFrequent(nums, k);
    for (auto n : res) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}