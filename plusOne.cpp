#include <bits/stdc++.h>
#include <math.h>

/*
You are given an integer array digits, where each digits[i] is the ith digit of a large integer. 
It is ordered from most significant to least significant digit, and it will not contain any leading zero.
Increment the large integer by one and return the resulting array of digits.
Return the digits of the given integer after incrementing it by one.


*/

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            result.push_back(sum % 10);
            carry = sum / 10;
        }
        if(carry > 0) {
            result.push_back(carry);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    vector<int> nums = {1,2,9};
    Solution s;
    vector<int> r = s.plusOne(nums);
    for(auto i: r)
        cout << i << " ";
    cout << endl;
    return 0;
}