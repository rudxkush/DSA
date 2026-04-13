#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<int>& beauty, int n) {
    sort(beauty.begin(), beauty.end());
    int maxiBeautyDiff = beauty[n - 1] - beauty[0];

    long long lowCount = 0, highCnt = 0;
    if (beauty[0] == beauty[n - 1]) {
        long long total = n;
        cout << 0 << " " << (total * (total - 1)) / 2;
        return;
    }

    int i = 0;
    while (i < n && beauty[i] == beauty[0]) {
        lowCount++;
        i++;
    }

    int j = n - 1;
    while (j >= 0 && beauty[j] == beauty[n - 1]) {
        highCnt++;
        j--;
    }

    long long ans = highCnt * lowCount;
    cout << maxiBeautyDiff << " " << ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> beauty(n);
    for(int i = 0; i < n; i++) {
        cin >> beauty[i];
    }
    solve(beauty, n);
    return 0;
}
