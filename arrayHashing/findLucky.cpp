#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/************** Find Lucky Integer in an Array ****************
https://leetcode.com/problems/find-lucky-integer-in-an-array
Given an array of integers arr, a lucky integer is an integer that has a
frequency in the array equal to its value. Return a lucky integer in the array.
If there are multiple lucky integers return the largest of them  If there is no
lucky integer return -1.

Example 1:
Input: arr = [2,2,3,4]
Output: 2
Explanation: The only lucky number in the array is 2 because frequency[2] ==
2.

Example 2:
Input: arr = [1,1,1,3]
Output: -1
Explanation: The only lucky number in the array is 1 because frequency[1] == 3.

Example 3:
Input: arr = [1,3,3,3]
Output: 3
Explanation: The only lucky number in the array is 3 because frequency[3] ==
3.
*/

class Solution {
   public:
    /*
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        int lucky = -1;
        for (const auto& [num, count] : freq) {
            if (num == count) {
                lucky = max(lucky, num);
            }
        }
        return lucky;
    }
};

int main() {
    Solution s;
    vector<int> arr1 = {2, 2, 3, 4};
    cout << "Lucky integer in [2, 2, 3, 4]: " << s.findLucky(arr1) << endl;

    vector<int> arr2 = {1, 1, 1, 3};
    cout << "Lucky integer in [1, 1, 1, 3]: " << s.findLucky(arr2) << endl;

    vector<int> arr3 = {1, 3, 3, 3};
    cout << "Lucky integer in [1, 3, 3, 3]: " << s.findLucky(arr3) << endl;

    return 0;
}