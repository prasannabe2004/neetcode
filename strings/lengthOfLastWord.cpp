#include <iostream>
#include <string>

using namespace std;

/*
Given a string s consisting of words and spaces, return the length of the last
word in the string. A word is a maximal substring consisting of non-space
characters only. Example 1: Input: s = "Hello World" Output: 5 Explanation: The
last word is "World", with a length of 5. Example 2: Input: s = "   fly me   to
the moon  " Output: 4 Explanation: The last word is "moon", with a length of 4.
Example 3:
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy", with a length of 6.
Constraints:
1 <= s.length <= 104
s consists of only English letters and spaces ' '.
*/

class Solution {
   public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        int count = 0;
        while (s[i] == ' ') i--;
        while (i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }
        return count;
    }
};

int main() {
    Solution sol;
    string s1 = "Hello World";
    cout << "Length of last word in \"" << s1
         << "\": " << sol.lengthOfLastWord(s1) << endl;

    string s2 = "   fly me   to the moon  ";
    cout << "Length of last word in \"" << s2
         << "\": " << sol.lengthOfLastWord(s2) << endl;

    string s3 = "luffy is still joyboy";
    cout << "Length of last word in \"" << s3
         << "\": " << sol.lengthOfLastWord(s3) << endl;

    return 0;
}