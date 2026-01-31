#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

/*
A valid email consists of a local name and a domain name, separated by the '@'
sign. Besides lowercase letters, the email may contain one or more '.' or '+'.

For example, in "alice@neetcode.io", "alice" is the local name, and
"neetcode.io" is the domain name. If you add periods '.' between some characters
in the local name part of an email address, mail sent there will be forwarded to
the same address without dots in the local name. Note that this rule does not
apply to domain names.

For example, "alice.z@neetcode.io" and "alicez@neetcode.io" forward to the same
email address. If you add a plus '+' in the local name, everything after the
first plus sign will be ignored. This allows certain emails to be filtered. Note
that this rule does not apply to domain names.

For example, "m.y+name@email.com" will be forwarded to "my@email.com".
It is possible to use both of these rules at the same time.
You are given an array of strings emails where we send one email to each
emails[i], return the number of different addresses that actually receive mails.

Example 1:
Input: emails =
["test.email+alex@neetcode.com","test.e.mail+bob.cathy@neetcode.com","testemail+david@nee.tcode.com"]
Output: 2

Example 2:
Input: emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
Output: 3
*/
class Solution {
   public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for (string email : emails) {
            string localname = email.substr(0, email.find('@'));
            string hostname = email.substr(email.find('@'), email.length());
            if (localname.find('+') != string::npos) {
                localname = localname.substr(0, localname.find('+'));
            }
            string newlocalname = "";
            for (char c : localname) {
                if (c != '.') {
                    newlocalname += c;
                }
            }
            s.insert(newlocalname + hostname);
        }
        return s.size();
    }
};

int main() {
    Solution s;
    vector<string> emails = {"test.email+alex@neetcode.com",
                             "test.e.mail+bob.cathy@neetcode.com",
                             "testemail+david@nee.tcode.com"};
    cout << s.numUniqueEmails(emails);
    return 0;
}