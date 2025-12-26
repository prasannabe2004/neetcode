#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void swapElements(int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void reverseArray(vector<int>& a, int start, int end) {
        while (start <= end) {
            swapElements(&a[start], &a[end]);
            start++;
            end--;
        }
    }
    vector<int> rotateArray(vector<int>& nums, int d) {
        d = d % nums.size();
        reverseArray(nums, 0, nums.size() - 1);
        // reverse(nums.begin(), nums.end());
        reverseArray(nums, 0, d - 1);
        // reverse(nums.begin(), nums.begin() + d);
        reverseArray(nums, d, nums.size() - 1);
        // reverse(nums.begin() + d, nums.end());
        return nums;
    }
};

int main() {
    vector<int> a{1, 2, 3, 4, 5, 6, 7};
    Solution s;
    s.rotateArray(a, 3);
    for (auto n : a) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
