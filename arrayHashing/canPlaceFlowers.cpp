#include <iostream>
#include <vector>

using namespace std;

/*
You are given an array where 0 represents empty spot and 1 represents occupied spot. You need to place n flowers in the flowerbed such that no two flowers are adjacent to each other.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: True

Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: False
*/

class Solution {
    public:
    /*
    Time Complexity: O(n)
    Space Complexity: O(1)
    */
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        int count = 0;
        for(int i = 1; i < flowerbed.size() - 1; i++) {
            if(flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0) {
                count++;
                flowerbed[i] = 1;
            }
        }
        return count >= n;
    }
};

int main() {
    Solution s;
    vector<int> v = {1,0,0,0,1};
    cout << (s.canPlaceFlowers(v, 1) == true) << endl;
    v = {0,0,1,0,0,0,0,0,1,0,0};
    cout << (s.canPlaceFlowers(v, 4) == true) << endl;
    return 0;
}