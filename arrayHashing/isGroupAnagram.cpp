/*
 * Given an array of strings strs, group the anagrams together.
 *
 * Expectation: Return a list of groups where each group contains anagrams.
 *
 * Example:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 */

#include <iostream>
using namespace std;

class Solution {
   public:
    /*
     * Time Complexity: O(n * m log m) - n strings, each sorted takes m log m
     * Space Complexity: O(n * m) - storing all strings in hash map
     */
    vector<vector<string>> groupAnagrams1(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> map;
        for (string str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            map[key].push_back(str);
        }
        for (auto it = map.begin(); it != map.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }

    /*
     * Time Complexity: O(n * m) - n strings, each processed in m time for
     * counting Space Complexity: O(n * m) - storing all strings in hash map
     */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (string str : strs) {
            vector<int> count(26, 0);
            for (char c : str) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; i++) {
                key += ',' + to_string(count[i]);
            }
            map[key].push_back(str);
        }
        vector<vector<string>> result;
        for (auto it = map.begin(); it != map.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = solution.groupAnagrams(strs);
    for (vector<string> group : result) {
        for (string str : group) {
            cout << str << " ";
        }
        cout << endl;
    }
}
