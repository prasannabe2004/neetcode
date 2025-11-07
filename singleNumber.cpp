#include <bits/stdc++.h>
#include <math.h>

/*
You are given a non-empty array of integers nums. Every integer appears twice except for one.
*/

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum = sum ^ nums[i];
        }
        return sum;
    }
};

    
int main() {
    Solution s;
    vector<int> nums = {2,2,3,5,5};
    int r = s.singleNumber(nums);
    cout << r << endl;
    return 0;
}