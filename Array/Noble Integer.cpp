int Solution::solve(vector<int> &A) {
    int n = (int) A.size();
    sort(A.begin(), A.end());
    for(int i = 0; i < n; i++) {
        if(i < n - 1 && A[i] == A[i + 1]) continue;
        if((n - i - 1) == A[i]) {
            return 1;
        }
    }
    return -1;
}
