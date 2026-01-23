#include <iostream>
#include <vector>
using namespace std;
/*
You are given an integer array cost where cost[i] is the cost of ith step on a
stair. Once you pay the cost, you can either climb one or two steps. You can
either start from the step with index 0, or the step with index 1. Return the
minimum cost to reach the top of the floor.

Example 1:
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
*/
class Solution {
   public:
    /*
    Bottom-Up Approach with DP Array
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
    int minCostClimbingStairsDP(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 0;

        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }
    /*
    Bottom-Up Approach with Space Optimization
    Time Complexity: O(n)
    Space Complexity: O(1)
    */
    int minCostClimbingStairs2(vector<int>& cost) {
        int n = cost.size();
        int first = 0;   // dp[i-2]
        int second = 0;  // dp[i-1]
        int current = 0;

        for (int i = 2; i <= n; i++) {
            current = min(second + cost[i - 1], first + cost[i - 2]);
            first = second;
            second = current;
        }
        return current;
    }
    /*
    Recursive Approach
    Time Complexity: O(2^n)
    Space Complexity: O(n)
    */
    int minCostClimbingStairsRecursive(vector<int>& cost) {
        return min(climb(cost, cost.size() - 1), climb(cost, cost.size() - 2));
    }
    int climb(vector<int>& cost, int n) {
        if (n < 0) return 0;
        if (n == 0 || n == 1) return cost[n];
        return cost[n] + min(climb(cost, n - 1), climb(cost, n - 2));
    }

    /*
    Top-Down Approach with Memoization
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
    int minCostClimbingStairsMemoization(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n + 1, -1);
        return min(climbMemo(cost, n - 1, memo), climbMemo(cost, n - 2, memo));
    }
    int climbMemo(vector<int>& cost, int n, vector<int>& memo) {
        if (n < 0) return 0;
        if (n == 0 || n == 1) return cost[n];
        if (memo[n] != -1) return memo[n];
        memo[n] = cost[n] + min(climbMemo(cost, n - 1, memo),
                                climbMemo(cost, n - 2, memo));
        return memo[n];
    }
    /*
    Bottom-Up Approach Modifying Input Array
    Time Complexity: O(n)
    Space Complexity: O(1)
    */
    int minCostClimbingStairs(vector<int>& cost) {
        for (int i = cost.size() - 3; i >= 0; i--) {
            cost[i] += min(cost[i + 1], cost[i + 2]);
        }
        return min(cost[0], cost[1]);
    }
};

int main() {
    Solution solution;
    vector<int> cost1 = {10, 15, 20};
    cout << solution.minCostClimbingStairs(cost1) << endl;  // Output: 15

    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << solution.minCostClimbingStairs(cost2) << endl;  // Output: 6

    return 0;
}