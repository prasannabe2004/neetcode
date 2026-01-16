#include <iostream>
#include <vector>

using namespace std;

/*
Function to find two numbers in a sorted array that sum up to a target value.
Returns the indices (1-based) of the two numbers if found, otherwise returns
{-1, -1}.

Example:
Input: numbers = [2,7,11,15], target = 13
Output: [1,2]

Explanation: The numbers at indices 1 and 2 (2 + 11) sum up to the target 13.
*/

class Solution {
   public:
    /* Implementation of two-sum using brute-force approach
     Time Complexity: O(n^2)
     Space Complexity: O(1)
     */
    vector<int> twoSumSortedBruteForce(const vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (numbers[i] + numbers[j] == target) {
                    return {i + 1, j + 1};  // 1-based indexing
                } else if (numbers[i] + numbers[j] > target) {
                    break;  // No need to check further as the array is sorted
                }
            }
        }
        return {-1, -1};  // Return an invalid pair if no solution is found
    }
    /* 
     Implementation of two-sum using two-pointer technique
     Time Complexity: O(n)
     Space Complexity: O(1)
     */
    vector<int> twoSumSorted(const vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1};  // 1-based indexing
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {-1, -1};  // Return an invalid pair if no solution is found
    }
};
int main() {
    Solution s;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 13;
    vector<int> result = s.twoSumSorted(numbers, target);
    cout << result[0] << " " << result[1] << endl;

    vector<int> resultBrute = s.twoSumSortedBruteForce(numbers, target);
    cout << resultBrute[0] << " " << resultBrute[1] << endl;
    return 0;
}