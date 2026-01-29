#include <iostream>
#include <string>

using namespace std;
/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1
*/

class Solution {
    public:
    /*
    Time Complexity: O(n*m) where n is length of haystack and m is length of needle
    Space Complexity: O(1)
    */
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        int m=needle.length();
        if(m==0) return 0;
        for(int i=0;i<=n-m;i++){
            int j = 0;
            for(;j<m;j++){
                if(haystack[i+j]!=needle[j])
                    break;
            }
            if(j==m)
                return i;
        }
        return -1;
    }
};

int main(){
    Solution s;
    cout<<s.strStr("hello","ell")<<endl;
    return 0;
}