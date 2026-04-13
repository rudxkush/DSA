#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

void solve(string& str, unordered_set<char>& keySet, int n, int k) {
    long long ans = 0;
    long long curr = 0;

    for(int j = 0; j < n; j++) {
        if(keySet.count(str[j])) {
            curr++;
            ans += curr;
        } else {
            curr = 0;
        }
    }

    cout << ans << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    unordered_set<char> keySet;
    for(int i = 0; i < k; i++) {
        char c;
        cin >> c;
        keySet.insert(c);
    }
    solve(str, keySet, n, k);
    return 0;
}
