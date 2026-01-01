#include <iostream>
#include <string>
#include <vector>

/*
Function to encode and decide a vector of strings into a single string
Example:
Input: ["HelloPrasana", "World"]
Output: "5#HelloPrasana5#World"
Explanation:
The output string is the encoded string where the integers in the string
indicates the number of characters to be skipped to form the next string in the
array. If no integers are to be skipped, then no '#' will be in the output
string. Example 2: Input: ["We", "say", ":", "yes"] Output: "2#We3#say2#:3#yes"
Explanation:
The output string is the encoded string where the integers in the string
*/
using namespace std;

class Solution {
   public:
    string encode(vector<string>& strs) {
        string res = "";
        for (auto s : strs) {
            res = res + to_string(s.length()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        int length = s.length();
        while (i < length) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j - i));
            res.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"HelloPrasana", "World"};
    string r = s.encode(strs);
    vector<string> out = s.decode(r);
    for (auto s : out) {
        cout << s << endl;
    }
    return 0;
}
