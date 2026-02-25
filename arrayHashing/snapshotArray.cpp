#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Problem: Snapshot Array
Design a data structure that supports the following interface:
- `SnapshotArray(int length)`: Initializes an array-like data structure with the
given length. Initially, each element equals `0`.
- `void set(int index, int val)`: Sets the element at the given `index` to be
equal to `val`.
- `int snap()`: Takes a snapshot of the array and returns the `snap_id`: the
total number of times we called `snap()` minus one.

Example:
Input: ["SnapshotArray","set","snap","set","get"]
[[3],[0,5],[],[0,6],[0,0]]
Output: [null,null,0,null,5]
Explanation:
SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
snapshotArr.set(0,5);  // Set array[0] = 5
snapshotArr.snap();  // Take a snapshot, return snap_id = 0
snapshotArr.set(0,6);  // Set array[0] = 6
snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return 5
*/
class Solution {
   private:
    vector<vector<pair<int, int>>> snapMap;
    int snapId = 0;

   public:
    /*
     Time Complexity: O(1)
     */
    void set(int key, int value) {
        if (snapMap.size() <= key) {
            snapMap.resize(key + 1);
        }
        snapMap[key].push_back({snapId, value});
    }
    /*
    Time Complexity: O(1)
    */
    void snap() { snapId++; }
    /*
    Time Complexity: O(log n)
    Complexity: O(m)
    */
    int get(int key, int snap_id) {
        if (snapMap.size() <= key) {
            return -1;
        }
        auto& arr = snapMap[key];
        int l = 0, r = arr.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid].first <= snap_id) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r >= 0 ? arr[r].second : -1;
    }
    void visualize() {
        for (int i = 0; i < snapMap.size(); i++) {
            cout << "Index " << i << ": ";
            for (const auto& p : snapMap[i]) {
                cout << "(" << p.first << ", " << p.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Solution solution;
    solution.set(0, 5);
    solution.set(1, 6);
    solution.set(2, 7);
    solution.set(3, 8);
    solution.set(4, 9);
    solution.snap();

    solution.set(5, 10);
    solution.set(2, 11);
    solution.visualize();
    solution.snap();
    solution.set(2, 6);
    solution.snap();
    solution.set(2, 13);
    solution.snap();
    solution.set(2, 14);
    solution.snap();
    solution.set(2, 15);

    solution.set(2, 17);
    solution.set(2, 18);

    solution.visualize();

    cout << solution.get(0, 0) << endl;  // Output: 5
    cout << solution.get(2, 0) << endl;  // Output: 11
    cout << solution.get(2, 1) << endl;  // Output: 6

    return 0;
}