#include <iostream>
#include <vector>

using namespace std;
/*
Find two missing numbers in an array of size n-2 containing numbers from 1 to n
Example:
Input: nums = [1, 2, 4, 6], n = 6
Output: [3, 5]
*/
class Solution {
   public:
    /*
    Use XOR to find the two missing numbers
     Time Complexity: O(n)
     Space Complexity: O(1)
    */
    vector<int> findMissingTwoNumbers(vector<int>& nums, int n) {
        int xorAll = 0;
        for (int i = 1; i <= n; i++) {
            xorAll ^= i;
        }
        for (int num : nums) {
            xorAll ^= num;
        }

        int rightmostSetBit = xorAll & (~(xorAll - 1));

        int num1 = 0, num2 = 0;
        for (int i = 1; i <= n; i++) {
            if (i & rightmostSetBit) {
                num1 ^= i;
            } else {
                num2 ^= i;
            }
        }
        for (int num : nums) {
            if (num & rightmostSetBit) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }

        return {num1, num2};
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 4, 6};
    int n = 6;
    vector<int> missingNumbers = s.findMissingTwoNumbers(nums, n);
    cout << "Missing numbers are: " << missingNumbers[0] << " and "
         << missingNumbers[1] << endl;
    return 0;
}