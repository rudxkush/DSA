int Solution::removeDuplicates(vector<int> &A) {
    int n = (int) A.size();
    if(n <= 2) return n;
    int cnt = 2;
    for(int i = 2; i < n; i++) {
        if(A[i] != A[cnt - 2]) {
            A[cnt] = A[i];
            cnt++;
        }
    }
    return cnt;
}
