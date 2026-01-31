#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;
/*
 Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some
 elements appear twice and others appear once. Find all the elements of [1, n]
 inclusive that do not appear in this array. Could you do it without extra space
 and in O(n) runtime? You may assume the returned list does not count as extra
 space.

 Example 1:
 Input: [4,3,2,7,8,2,3,1]
 Output: [5,6]
 E
 Explanation:
 The numbers in the range [1,8] that do not appear in this array are [5,6].

 Example 2:
 Input: [1,1]
 Output: [2]
 Explanation:
 The numbers in the range [1,2] that do not appear in this array are [2].
*/
class Solution {
   public:
   /*
    This is the best solution. The key insight is to use the array itself as a
    hash table. Since all numbers are in range [1,n], we can use the index of the
    array to represent the number. For each number, we mark the number at its
    corresponding index as negative. Then we iterate through the array again,
    and if a number is positive, it means the index+1 is missing.
    Time Complexity: O(n)
    Space Complexity: O(1)
   */
   vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] *= -1;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
    /*
    Using hashmap
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
    vector<int> findDisappearedNumbersHashMap(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }

        vector<int> result;
        for (int i = 1; i <= nums.size(); i++) {
            if (m[i] == 0) result.push_back(i);
        }
        return result;
    }
    /*
    Using set
    Time Complexity: O(n)
    Space Complexity: O(n)
    */
    vector<int> findDisappearedNumbersSet(vector<int>& nums) {
        unordered_set<int> seen;
        vector<int> result;
        for (int i = 1; i <= nums.size(); i++) {
            seen.insert(i);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (seen.find(nums[i]) != seen.end()) {
                seen.erase(nums[i]);
            }
        }
        for (auto a : seen) {
            result.push_back(a);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> input = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result = s.findDisappearedNumbersSet(input);
    for (int i : result) cout << i << " ";
    cout << endl;
    result = s.findDisappearedNumbersHashMap(input);
    for (int i : result) cout << i << " ";
    cout << endl;
    result = s.findDisappearedNumbers(input);
    for (int i : result) cout << i << " ";
    cout << endl;
    return 0;
}
