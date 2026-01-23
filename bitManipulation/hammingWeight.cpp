#include <iostream>

using namespace std;

/*
Count number of set bits in a given integer
*/
class Solution {
   public:
    int hammingWeight(unsigned int n) {
        unsigned int count = 0;
        while (n > 0) {
            unsigned int isBitSet = n & 1;
            if (isBitSet) count++;
            n >>= 1;
        }
        return count;
    }
};

int main() {
    Solution s;
    cout << s.hammingWeight(123) << endl;
}