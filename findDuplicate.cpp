#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_set>

/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.
Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
*/

using namespace std;

class Solution
{
public:
     /*
     Using sorting and then comparing adjacent elements
     Time complexity: O(nlogn)
     Space complexity: O(1)
     */
     int findDuplicate1(std::vector<int> &nums)
     {
          sort(nums.begin(), nums.end());
          for (int i = 0; i < nums.size() - 1; i++)
          {
               if (nums[i] == nums[i + 1])
               {
                    return nums[i];
               }
          }
          return -1;
     }
     /*
     Using Hashset
     Time complexity: O(n)
     Space complexity: O(n)
     */
     int findDuplicate2(std::vector<int> &nums)
     {
          unordered_set<int> s;
          for (int num : nums)
          {
               if (s.count(num))
                    return num;
               s.insert(num);
          }
          return -1;
     }
     /*
     Using Floyd's cycle detection algorithm
     Time complexity: O(n)
     Space complexity: O(1)
     */
     int findDuplicate3(std::vector<int> &nums)
     {
          int slow = 0;
          int fast = 0;

          while (true)
          {
               slow = nums[slow];
               fast = nums[nums[fast]];
               if (slow == fast)
                    break;
          }

          int slow2 = 0;
          while (true)
          {
               slow = nums[slow];
               slow2 = nums[slow2];
               if (slow == slow2)
                    break;
          }
          return slow2;
     }
     /*
     Using negative marking
     Time complexity: O(n)
     Space complexity: O(1)
     */
     int findDuplicate4(std::vector<int> &nums)
     {
          for (int num : nums)
          {
               int index = abs(num);
               if (nums[index] < 0)
                    return index;
               nums[index] = -nums[index];
          }
          return -1;
     }
     /*
     Using binary search
     Time complexity: O(nlogn)
     Space complexity: O(1)
     */
     int findDuplicate5(std::vector<int> &nums)
     {
          int left = 1;
          int right = nums.size() - 1;

          while (left < right)
          {
               int mid = left + (right - left) / 2;
               int count = 0;
               for (int num : nums)
               {
                    if (num <= mid)
                         count++;
               }
               if (count > mid)
                    right = mid;
               else
                    left = mid + 1;
          }
          return left;
     }
     /*
     Using bit manipulation
     Time complexity: O(n)
     Space complexity: O(1)
     */
     int findDuplicate(std::vector<int> &nums)
     {
          int result = 0;
          for (int i = 0; i < nums.size(); i++)
          {
               result ^= nums[i];
               result ^= i;
          }
          return result;
     }
};

int main()
{
     Solution s;
     vector<int> nums = {1, 3, 4, 2, 2};
     cout << s.findDuplicate(nums) << endl;
     return 0;
}
