 #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution { 
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) 
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            while(l < r) {
                int t = nums[i] + nums[l] + nums[r];
                if( t == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    r--;
                    l++;
                    while(l < r && nums[l] == nums[l-1])
                        l++;
                } else if (t > 0) {
                    r--;
                } else {
                    left++;
                }
            }
        }
    }
};

