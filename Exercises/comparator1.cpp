#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Custom comparator for sorting pairs
bool customComparator(const pair<int, int>& a, const pair<int, int>& b) {
    // Sort primarily by the first element (ascending)
    // If the first elements are equal, sort by the second element (descending)
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    vector<pair<int, int>> vec = {{3, 5}, {1, 9}, {3, 2}, {1, 8}, {2, 4}};

    cout << "Original vector of pairs:\n";
    for (const auto& p : vec) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << '\n';

    sort(vec.begin(), vec.end(), customComparator);

    cout << "Sorted vector of pairs:\n";
    for (const auto& p : vec) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << '\n';

    return 0;
}
