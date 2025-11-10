#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
Two Sum Problem:
Given an array of integers nums and an integer target, return indices of the two numbers
that add up to target. You may assume that each input would have exactly one solution,
and you may not use the same element twice.

Solution Approach:
Uses a hash map (unordered_map) to store previously seen numbers and their indices.
For each number, calculates the complement (target - current number) and checks if it
exists in the hash map. If found, returns the indices; otherwise, stores the current
number and its index in the map.

Time Complexity: O(n) - single pass through the array
Space Complexity: O(n) - hash map stores up to n elements

Example:
Input: nums = [2,7,11,15], target = 9
Output: [0,1] (because nums[0] + nums[1] = 2 + 7 = 9)
*/
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < sizeof(nums); i++)
        {
            int complement = target - nums[i];
            if (m.find(complement) != m.end())
            {
                vector<int> result = {m[complement], i};
                return result;
            }
            else
            {
                m[nums[i]] = i;
            }
        }
        return {};
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = s.twoSum(nums, target);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
