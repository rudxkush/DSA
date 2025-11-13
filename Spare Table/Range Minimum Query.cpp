/*
  Author: rudxkush
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class SparseTableRMQ {
public:
    vector<vector<int>> st;   // stores indices of minima
    vector<int> arr;
    int n, maxLog;

    SparseTableRMQ(vector<int>& input) {
        arr = input;
        n = (int)arr.size();
        maxLog = log2(n);
        st.assign(n, vector<int>(maxLog + 1));
        build();
    }

    void build() {
        for (int i = 0; i < n; i++) st[i][0] = i;

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                int left = st[i][j - 1];
                int right = st[i + (1 << (j - 1))][j - 1];
                st[i][j] = (arr[left] < arr[right]) ? left : right;
            }
        }
    }

    int query(int l, int r) {
        int len = r - l + 1;
        int k = log2(len);
        int left = st[l][k];
        int right = st[r - (1 << k) + 1][k];
        return min(arr[left], arr[right]);
    }
};

int main() {
    vector<int> input = {2, 5, 3, 6, 4, 1, -1, 3, 4, 2};
    SparseTableRMQ rmq(input);

    for (int i = 0; i < (int)input.size(); i++) {
        for (int j = i; j < (int)input.size(); j++) {
            cout << rmq.query(i, j) << " ";
        }
        cout << endl;
    }
}
