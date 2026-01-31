#include <iostream>
using namespace std;

/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example:
n = 10, I pick 6.
Return 6.
*/
class Solution {
   public:
    int pick = 1;
    int guess(int g) {
        if (g > pick) return -1;
        if (g < pick) return 1;
        return 0;
    }
    /*
    Time Complexity: O(logn)
    Space Complexity: O(1)
    */
    int guessNumber(int n) {
        int l = 1;
        int r = n;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int res = guess(m);
            if (res > 0) {
                l = m + 1;
            } else if (res < 0) {
                r = m - 1;
            } else {
                return m;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    cout << s.guessNumber(10) << endl;
}