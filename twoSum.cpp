/*
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 *
 * Expectation: Return array of two indices where nums[i] + nums[j] = target.
 *
 * Example:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
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
