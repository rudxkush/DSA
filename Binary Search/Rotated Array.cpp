int Solution::findMin(const vector<int> &A) {
    int n = (int) A.size();
    for(int i = 1; i < n; i++) {
        if(A[i] < A[i - 1]) {
            return A[i];
        }
    }    
    return A[0];
}
