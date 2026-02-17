#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
Given an array of integers temperatures represents the daily temperatures,
return an array answer such that answer[i] is the number of days you have to
wait after the ith day to get a warmer temperature. If there is no future day
for which this is possible, keep answer[i] == 0 instead.

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]

*/
class Solution {
   public:
    /*
    Brute Force
    Time Complexity: O(n^2)
    Space Complexity: O(n)
    */
    vector<int> dailyTempaturesBruteForce(vector<int>& temperatures) {
        vector<int> result;
        int n = temperatures.size();
        for (int i = 0; i < n; i++) {
            int count = 0;
            int j = i + 1;
            while (j < n) {
                if (temperatures[j] > temperatures[i]) {
                    break;
                }
                j++;
                count++;
            }
            count = (j == n) ? 0 : count + 1;
            result.push_back(count);
        }
        return result;
    }
    /*
    Using Stack
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stack;  // pair: {temp, index}

        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            while (!stack.empty() && t > stack.top().first) {
                for (auto r : res) {
                    cout << r << " ";
                }
                cout << endl;
                auto pair = stack.top();
                // cout << pair.first << " " << pair.second << endl;
                stack.pop();
                res[pair.second] = i - pair.second;
            }
            stack.push({t, i});
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = s.dailyTemperatures(temperatures);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}