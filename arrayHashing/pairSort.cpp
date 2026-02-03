#include <iostream>

using namespace std;

int main() {
    // Sample vector of pairs
    vector<pair<int, int>> vec = {{3, 5}, {1, 9}, {4, 2}, {2, 8}, {5, 2}};

    cout << "Original vector of pairs:\n";
    for (auto& p : vec) cout << "(" << p.first << ", " << p.second << ") ";
    cout << "\n\n";

    sort(vec.begin(), vec.end());
    cout << "Sorted by Asending order:\n";
    for (auto& p : vec) cout << "(" << p.first << ", " << p.second << ") ";
    cout << "\n\n";

    sort(vec.rbegin(), vec.rend());
    cout << "Sorted by desending order:\n";
    for (auto& p : vec) cout << "(" << p.first << ", " << p.second << ") ";
    cout << "\n";

    return 0;
}
