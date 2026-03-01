#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    /*
     Quick Sort Algorithm
      Time Complexity: O(n log n)
      Space Complexity: O(n)
      Note: This implementation is not in-place and uses additional space for
     the left and right vectors. In-place quicksort can be implemented using the
     Lomuto or Hoare partition scheme, which would reduce the space complexity
     to O(log n) on average. However, the provided implementation is
     straightforward and easy to understand for educational purposes.
    */
    vector<int> quickSortArray(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums;
        }
        int pivot = nums[nums.size() / 2];
        vector<int> left, right;
        for (int i = 0; i < nums.size(); i++) {
            if (i == nums.size() / 2) {
                continue;  // Skip the pivot element
            }
            if (nums[i] < pivot) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }
        vector<int> sortedLeft = quickSortArray(left);
        vector<int> sortedRight = quickSortArray(right);
        sortedLeft.push_back(pivot);
        sortedLeft.insert(sortedLeft.end(), sortedRight.begin(),
                          sortedRight.end());
        return sortedLeft;
    }
    /*
    Bubble Sort Algorithm
     Time Complexity: O(n^2)
     Space Complexity: O(1)
    */
    vector<int> bubbleSortArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] > nums[j]) {
                    swap(nums[i], nums[j]);
                }
            }
        }
        return nums;
    }
};

int main() {
    vector<int> a{5, 2, 3, 1};
    Solution s;
    vector<int> result = s.quickSortArray(a);
    for (auto n : result) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
