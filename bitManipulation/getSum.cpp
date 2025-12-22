#include <iostream>

using namespace std;

/*
Find the sum without using + operator
Example 1:
Input: a = 2, b = 3
Output: 5
*/

class Solution {
   public:
    int getSum(int a, int b) {
        int sum = 0;
        int carry = 0;
        while (b != 0) {
            sum = a ^ b;
            carry = a & b;
            a = sum;
            b = carry << 1;
        }
        return a;
    }
};

int main() {
    Solution s;
    cout << s.getSum(9, 11) << endl;
    return 0;
}
