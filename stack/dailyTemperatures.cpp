#include <iostream>
#include <vector>
using namespace std;

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
    Stack
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stack;  // pair: {temp, index}

        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            while (!stack.empty() && t > stack.top().first) {
                auto pair = stack.top();
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
    vector<int> result = s.dailyTempatures(temperatures);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}