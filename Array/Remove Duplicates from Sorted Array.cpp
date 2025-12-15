int Solution::removeDuplicates(vector<int> &A) {
    int n = A.size();
    int index = 0;
    for(int i = 0; i < n; i++) {
        if(i < n - 1 && A[i] != A[i + 1]) {
            A[index] = A[i];
            index++;
        }
    }
    if((index - 1 > 0) && A[n - 1] != A[index - 1]) A[index] = A[n - 1];
    return index + 1;
}
