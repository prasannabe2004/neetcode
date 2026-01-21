#include <iostream>
#include <vector>

using namespace std;

/*
Replace Greatest Element on Right Side
https://leetcode.com/problems/replace-greatest-element-on-right-side-of-array/
Given an array arr, replace every element in that array with the greatest
element among the elements to its right, and replace the last element with -1.
After doing so, return the array.

Example 1:
Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
Explanation:
- index 0 --> the greatest element to the right of index 0 is index 1 (18).
- index 1 --> the greatest element to the right of index 1 is index 4 (6).
- index 2 --> the greatest element to the right of index 2 is index 4 (6).
- index 3 --> the greatest element to the right of index 3 is index 4 (6).
- index 4 --> the greatest element to the right of index 4 is index 5 (1).
- index 5 --> there are no elements to the right of index 5, so we put -1.
*/

class Solution {
   public:
    /*
     Time Complexity: O(n)
     Space Complexity: O(1)
    */
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxRight = -1;  // Initialize the maximum element to the right

        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; i--) {
            int current = arr[i];  // Store the current element
            arr[i] = maxRight;  // Replace with the maximum element to the right
            maxRight = max(maxRight, current);  // Update maxRight if needed
        }
        return arr;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {17, 18, 5, 4, 6, 1};
    vector<int> result1 = sol.replaceElements(arr1);
    cout << "Replaced Array 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> arr2 = {400};
    vector<int> result2 = sol.replaceElements(arr2);
    cout << "Replaced Array 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}