#include <math.h>

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

/*
Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array.

Solution uses XOR operation: XOR of all numbers from 0 to n and all numbers in
the array. Since x ^ x = 0 and x ^ 0 = x, all numbers except the missing one
will cancel out. Time Complexity: O(n), Space Complexity: O(1)
*/

using namespace std;

class Solution {
   public:
    int missingNumberXOR(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        int n = nums.size();
        int r = n;
        for (int i = 0; i < n; i++) {
            r = r ^ i ^ nums[i];
        }
        return r;
    }
    int missingNumberSorting(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return nums.size();
    }
    int missingNumberMath(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;
        for (int num : nums) {
            actualSum += num;
        }
        return expectedSum - actualSum;
    }
    int missingNumberHashSet(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int num : nums) {
            numSet.insert(num);
        }
        for (int i = 0; i <= nums.size(); i++) {
            if (numSet.find(i) == numSet.end()) {
                return i;
            }
        }
        return -1;  // This line should never be reached
    }
};

int main() {
    Solution s;

    // Test Case 1: Missing number in middle
    vector<int> nums1 = {3, 0, 1};
    cout << "Test Case 1: [3, 0, 1]" << endl;
    cout << "Missing Number: " << s.missingNumberXOR(nums1) << endl;
    cout << "Expected: 2" << endl << endl;

    // Test Case 2: Missing number at end
    vector<int> nums2 = {0, 1};
    cout << "Test Case 2: [0, 1]" << endl;
    cout << "Missing Number: " << s.missingNumberXOR(nums2) << endl;
    cout << "Expected: 2" << endl << endl;

    // Test Case 3: Missing number at beginning
    vector<int> nums3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << "Test Case 3: [9, 6, 4, 2, 3, 5, 7, 0, 1]" << endl;
    cout << "Missing Number: " << s.missingNumberXOR(nums3) << endl;
    cout << "Expected: 8" << endl << endl;

    // Test Case 4: Missing 0
    vector<int> nums4 = {1, 2, 3, 4};
    cout << "Test Case 4: [1, 2, 3, 4]" << endl;
    cout << "Missing Number: " << s.missingNumberXOR(nums4) << endl;
    cout << "Expected: 0" << endl << endl;

    // Test Case 5: Single element, missing 1
    vector<int> nums5 = {0};
    cout << "Test Case 5: [0]" << endl;
    cout << "Missing Number: " << s.missingNumberXOR(nums5) << endl;
    cout << "Expected: 1" << endl << endl;

    // Test Case 6: Single element, missing 0
    vector<int> nums6 = {1};
    cout << "Test Case 6: [1]" << endl;
    cout << "Missing Number: " << s.missingNumberXOR(nums6) << endl;
    cout << "Expected: 0" << endl << endl;

    cout << "All test cases completed!" << endl;

    // Using sorting method
    cout << "Using Sorting Method:" << endl;
    cout << "Test Case 1: [3, 0, 1]" << endl;
    cout << "Missing Number: " << s.missingNumberSorting(nums1) << endl;
    cout << "Expected: 2" << endl << endl;

    return 0;
}
