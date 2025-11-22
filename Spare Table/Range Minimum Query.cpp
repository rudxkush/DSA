/*
  Author: rudxkush
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "Enter size of the input array: ";
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<vector<int>> queries = {{3, 5}, {3, 6}, {0, 5}, {0, 3}}; // Q -> {[start end], .....}

    // building sparse table
    vector<vector<int>> sparseTable(n, vector<int>(log2(n) + 1, INT_MAX));
    // pre-processing step
    for (int i = 0; i < n; i++) {
        sparseTable[i][0] = nums[i]; // for a single element, length = 2^0 = 1
    }
    for (int j = 1;  j <= log2(n); j++) { // for each length represented in the power of 2s
        for (int i = 0; i + (1 << j) - 1 < n; i++) {    // with their respective start index
            // we calculate the minimum element
            sparseTable[i][j] = min(sparseTable[i][j - 1], sparseTable[i + (1 << (j - 1))][j - 1]);
        }
    }

    // print sparse matrix in O(nlogn)
    // for (auto i : sparseTable) {
    //     for (auto ij : i) {
    //         cout << ij << " ";
    //     }
    //     cout << endl;
    // }

    // query in O(1)
    for (auto query : queries) {
        int L = query[0];
        int R = query[1];
        int len = log2(R - L + 1);
        int answer = min(sparseTable[L][len], sparseTable[R - (1 << len) + 1][len]);
        cout << answer << endl;
    }
    return 0;
}
