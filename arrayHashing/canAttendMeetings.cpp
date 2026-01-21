#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
Given an array of meeting time intervals consisting of start and end times
[[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all
meetings.

Example 1:
Input: [[0,30],[5,10],[15,20]]
Output: false

Example 2:
Input: [[7,10],[2,4]]
Output: true
*/
class Intervals {
   public:
    int start;
    int end;
    Intervals(int s, int e) : start(s), end(e) {}
};

class Solution {
   public:
    /*
    Time Complexity: O(N log N) due to sorting the intervals.
    Space Complexity: O(1) if the sorting is done in place.
    */
    bool canAttendMeetings(vector<Intervals>& intervals) {
        if (intervals.empty()) return {};

        // Sort intervals based on the starting time
        sort(intervals.begin(), intervals.end(),
             [](auto& a, auto& b) { return a.start < b.start; });
        for (int i = 1; i < intervals.size(); i++) {
            int prev_end = intervals[i - 1].end;
            int next_start = intervals[i].start;
            if (next_start < prev_end) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<Intervals> intervals = {Intervals(1, 3), Intervals(2, 4),
                                   Intervals(5, 7)};
    bool canMerge = sol.canAttendMeetings(intervals);
    cout << (canMerge ? "Intervals can be merged."
                      : "Intervals cannot be merged.")
         << endl;
    intervals = {Intervals(1, 2), Intervals(3, 4), Intervals(5, 6)};
    canMerge = sol.canAttendMeetings(intervals);
    cout << (canMerge ? "Intervals can be merged."
                      : "Intervals cannot be merged.")
         << endl;
    return 0;
}