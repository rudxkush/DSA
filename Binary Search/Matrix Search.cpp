int Solution::searchMatrix(vector<vector<int> > &A, int target) {
    int n = (int) A.size();
    int m = (int) A[0].size();
    int start = 0, end = n*m - 1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        int row = mid / m;
        int col = mid % m;
        if(A[row][col] == target) {
            return 1;
        } else if(A[row][col] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return 0;
}
