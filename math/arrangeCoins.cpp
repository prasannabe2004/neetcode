#include <iostream>
using namespace std;
/*
You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Return the number of complete rows of the staircase you will build.

Example 1:
Input: n = 5
Output: 2

Example 2:
Input: n = 9
Output: 3
*/
class Solution {
   public:
   /*
   Time Complexity: O(sqrt(n))
   Space Complexity: O(1)
   */
    int arrangeCoins(int n) {
        int k = 0;
        while (n - k > 0) {
            k++;
            n = n - k;
        }
        return k;
    }
    /*
    Time Complexity: O(log n)
    Space Complexity: O(1)
     */
    int arrangeCoinsBinarySearch(int n) {
        int l = 1;
        int r = n;
        int res = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int coins = m * (m + 1) / 2.0;
            if (coins > n) {
                r = m - 1;
            } else if (coins < n) {
                l = m + 1;
                res = max(res, m);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.arrangeCoins(5) << endl;
    cout << s.arrangeCoinsBinarySearch(5) << endl;

    return 0;
}