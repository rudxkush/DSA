int Solution::solve(vector<int> &A, int B) {
    int start = 0;
    int end = A.size() - 1;
    int bestRight = -1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(A[mid] == B) {
            bestRight = mid;
            start = mid + 1;
        } else if(A[mid] > B) {
            end = mid - 1;
        } else {
            bestRight = mid;
            start = mid + 1;
        }
    }
    return bestRight + 1;
}
