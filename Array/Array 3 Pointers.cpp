int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int i = 0, j = 0, k = 0;
    int ans = INT_MAX;

    while (i < A.size() && j < B.size() && k < C.size()) {
        int maxVal = max({A[i], B[j], C[k]});
        int minVal = min({A[i], B[j], C[k]});

        ans = min(ans, maxVal - minVal);

        if (minVal == A[i]) i++;
        else if (minVal == B[j]) j++;
        else k++;
    }
    return ans;
}
