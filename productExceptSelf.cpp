#include <iostream>
#include <vector>
#include <math.h>

/*
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
 *
 * Expectation: Return array where each element is the product of all other elements.
 *
 * Example:
 * Input: nums = [1,2,3,4]
 * Output: [24,12,8,6]
 */

using namespace std;

class Solution
{
public:
     /*
     3 vector used
     Time Complexity: O(n)
     Space Complexity: O(n)
     */
     vector<int> productExceptSelf1(vector<int> &nums)
     {
          int n = nums.size();
          vector<int> output(n);
          vector<int> prefix(n);
          vector<int> postfix(n);
          prefix[0] = 1;
          for (int i = 1; i < n; i++)
          {
               prefix[i] = prefix[i - 1] * nums[i - 1];
          }

          postfix[n - 1] = 1;
          for (int i = n - 2; i >= 0; i--)
          {
               postfix[i] = postfix[i + 1] * nums[i + 1];
          }
          for (int i = 0; i < nums.size(); i++)
          {
               output[i] = prefix[i] * postfix[i];
          }
          return output;
     }
     /*
     Single vector used
     Time Complexity: O(n)
     Space Complexity: O(n)
     */
     vector<int> productExceptSelf2(vector<int> &nums)
     {
          int n = nums.size();
          vector<int> output(n);
          output[0] = 1;
          for (int i = 1; i < n; i++)
          {
               output[i] = output[i - 1] * nums[i - 1];
          }
          int postfix = 1;
          for (int i = n - 1; i >= 0; i--)
          {
               output[i] = output[i] * postfix;
               postfix = postfix * nums[i];
          }
          return output;
     }
     /*
     Brute Force
     Time Complexity: O(n^2)
     Space Complexity: O(n)
     */
     vector<int> productExceptSelf3(vector<int> &nums)
     {
          int n = nums.size();
          vector<int> output(n, 1);
          for (int i = 0; i < n; i++)
          {
               for (int j = 0; j < n; j++)
               {
                    if (i != j)
                    {
                         output[i] = output[i] * nums[j];
                    }
               }
          }
          return output;
     }
     /*
     Using division
     Time Complexity: O(n)
     Space Complexity: O(1)
     */
     vector<int> productExceptSelf(vector<int> &nums)
     {
          int n = nums.size();
          vector<int> output(n);
          int product = 1;
          for (int i = 0; i < n; i++)
          {
               product = product * nums[i];
          }
          for (int i = 0; i < n; i++)
          {
               output[i] = product / nums[i];
          }
          return output;
     }
};

int main()
{
     Solution s;
     vector<int> nums = {1, 2, 3, 4};
     vector<int> result = s.productExceptSelf(nums);
     for (int i = 0; i < result.size(); i++)
     {
          cout << result[i] << " ";
     }
     return 0;
}
