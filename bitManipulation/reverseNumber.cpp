#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

/*
Find the reverse of a number
Ex: 1234 -> 4321
if number is negative, reverse the number and then multiply by -1
if number is positive, reverse the number
if number is greater than 32 bit range, return 0
*/

int MAX = std::numeric_limits<int>::max();
int MIN = std::numeric_limits<int>::min();

class Solution {
   public:
    // Convert into string and reverse it and convert back to integer
    int reverse2(int x) {
        int sign = 1;
        if (x < 0) {
            sign = -1;
        }
        string s = to_string(x);
        std::reverse(s.begin(), s.end());
        long long res = stoll(s);
        if (res > INT_MAX || res < INT_MIN) {
            return 0;
        }
        if (sign == -1) res = -res;
        return (int)res;
    }
    // Reverse the number digit by digit
    int reverse(int x) {
        int result = 0;
        int sign = 1;

        if (x < 0) {
            sign = -1;
            x = x * sign;
        }
        while (x > 0) {
            int digit = x % 10;
            if (result > MAX / 10 ||
                ((result == MAX / 10) && (digit > MAX % 10))) {
                return 0;
            }
            if (result < MIN / 10 ||
                ((result == MIN / 10) && (digit > MIN % 10))) {
                return 0;
            }
            result = result * 10 + digit;
            x = x / 10;
        }
        return result * sign;
    }
};

int main() {
    Solution s;
    cout << "Testing MAX " << s.reverse(MAX) << endl;
    cout << "Testing MIN " << s.reverse(MIN) << endl;
    cout << "Testing +ve " << s.reverse2(1234) << endl;
    cout << "Testing -ve " << s.reverse2(-1234) << endl;

    return 0;
}
