#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*
You are given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

Each character in text can only be used once. Return the maximum number of instances that can be formed.

Example 1:
Input: text = "nlaebolko"
Output: 1

Example 2:
Input: text = "loonbalxballpoon"
Output: 2
*/
class Solution {
   public:
   /*
   Time Complexity: O(n)
   Space Complexity: O(1)
   */
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> m;
        unordered_map<char, int> b;

        for (char c : text) {
            m[c]++;
        }
        string balloon("balloon");
        for (char c : balloon) {
            b[c]++;
        }

        int res = text.length();
        for (auto& c : b) {
            res = min(res, m[c.first] / c.second);
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.maxNumberOfBalloons("nlaebolko") << endl;
    return 0;
}