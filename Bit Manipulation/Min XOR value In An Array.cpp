int Solution::findMinXor(vector<int> &v) {
    sort(v.begin(), v.end());
    int ans = INT_MAX;
    for(int i = 0; i < (int) v.size() - 1; i++) {
        ans = min(ans, v[i] ^ v[i + 1]);
    }
    return ans;
}
