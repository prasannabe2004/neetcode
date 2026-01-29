#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Given a array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the array is non-empty and always has a majority element.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

class Solution {
    public:
    /*
    Boyer-Moore Majority Vote Algorithm
    Time Complexity: O(n)
    Space Complexity: O(1)
    */
    int majorityElement(vector<int>& nums) {
         int count = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(count == 0) {
                res = nums[i];
            }
            if(res == nums[i]) {
                count++;
            } else {
                count--;
            }

        }
        return res;
    }
    /*
    Using Hashmap
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
    int majorityElement2(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
            if(m[nums[i]] > nums.size()/2) {
                return nums[i];
            }
        }
        return -1;
    }
    /*
    Brute Force Approach
    Time Complexity: O(n^2)
    Space Complexity: O(1)
    */
    int majorityElementBruteForce(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int count = 0;
            for(int j = 0; j < nums.size(); j++) {
                if(nums[i] == nums[j]) {
                    count++;
                }
                if(count > nums.size()/2) {
                    return nums[i];
                }
            }
        }
        return -1;
    }
    /*
    Using Sorting
    Time Complexity: O(nlogn)
    Space Complexity: O(1)
    */
    int majorityElementSorting(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2,2,1,1,1,2,2};
    int result = s.majorityElement(nums);
    cout << result << endl;
    result = s.majorityElement2(nums);
    cout << result << endl;
    return 0;
}

