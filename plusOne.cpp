/*
 * Given a large integer represented as an integer array digits, increment the
 * integer by one and return the resulting array.
 *
 * Expectation: Return the digits array after adding 1 to the represented
 * number.
 *
 * Example:
 * Input: digits = [1,2,3]
 * Output: [1,2,4]
 */

#include <bits/stdc++.h>
#include <math.h>

using namespace std;

class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            result.push_back(sum % 10);
            carry = sum / 10;
        }
        if (carry > 0) {
            result.push_back(carry);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    vector<int> nums = {1, 2, 9};
    Solution s;
    vector<int> r = s.plusOne(nums);
    for (auto i : r) cout << i << " ";
    cout << endl;
    return 0;
}