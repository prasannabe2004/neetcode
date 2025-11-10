#include <iostream>
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