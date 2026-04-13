#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& temp, int k, int q) {
    long long ans = 0;
    long long count = 0;

    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] <= q) {
            count++;
            if (count >= k) {
                ans += (count - k + 1);
            }
        } else {
            count = 0;
        }
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> temp(n);

        for (int i = 0; i < n; i++) {
            cin >> temp[i];
        }

        solve(temp, k, q);
    }
    return 0;
}
