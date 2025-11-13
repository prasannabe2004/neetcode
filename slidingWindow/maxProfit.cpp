/*
 * Given an array prices where prices[i] is the price of a given stock on the
 * ith day, find the maximum profit you can achieve.
 *
 * Expectation: Return the maximum profit from buying and selling stock (buy
 * before sell).
 *
 * Example:
 * Input: prices = [7,1,5,3,6,4]
 * Output: 5
 */

#include <iostream>
using namespace std;
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 1;
        int profit = 0;
        int maxProfit = 0;
        while (right < prices.size()) {
            if (prices[left] < prices[right]) {
                profit = prices[right] - prices[left];
                maxProfit = max(maxProfit, profit);
            } else {
                left = right;
            }
            right++;
        }
        return maxProfit;
    }
};

int main() {
    Solution s;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(prices) << endl;
    return 0;
}
