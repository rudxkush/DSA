vector<int> Solution::solve(vector<int> &A) {
    // sort(A.begin(), A.end());
    int n = (int) A.size();
    int i = 0;
    int j = n - 1;
    while(i < j) {
        // what if 0 is present at ith index
        if(A[i] == 0) {
            i++;
        }
        // what if 1 is present at ith index
        else {
            swap(A[i], A[j]);
            j--;
        }
    }
    return A;
}
