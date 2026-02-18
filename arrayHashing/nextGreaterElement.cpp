#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        stack<int> s;
        unordered_map<int, int> nextGreaterMap;

        for (int num : nums2) {
            while (!s.empty() && s.top() < num) {
                nextGreaterMap[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        while (!s.empty()) {
            nextGreaterMap[s.top()] = -1;
            s.pop();
        }

        for (int num : nums1) {
            result.push_back(nextGreaterMap[num]);
        }

        return result;
    }
}