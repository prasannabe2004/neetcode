#include <iostream>
#include <vector>
using namespace std;

/*
Find the contiguous subarray within an array (containing at least one number)
which has the largest product.
Example: Input: [2,3,-2,4],
Output: 6
Explanation: [2,3] has the largest product = 6.
*/

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                swap(maxProd, minProd);
            }
            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);
            result = max(result, maxProd);
        }
        return result;
    }
    int bruteForceMaxProduct(vector<int>& nums) {
        int maxProduct = nums[0];
        for (size_t i = 0; i < nums.size(); ++i) {
            int currentProduct = 1;
            for (size_t j = i; j < nums.size(); ++j) {
                currentProduct *= nums[j];
                maxProduct = max(maxProduct, currentProduct);
            }
        }
        return maxProduct;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {2, 3, -2, 4};
    cout << "Maximum Product Subarray: " << sol.maxProduct(nums) << endl;
    cout << "Brute Force Maximum Product Subarray: "
         << sol.bruteForceMaxProduct(nums) << endl;
    return 0;
}