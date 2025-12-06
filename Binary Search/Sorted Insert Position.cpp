int Solution::searchInsert(vector<int> &A, int target) {
    int ans = -1, n = (int) A.size();
    int start = 0, end = n - 1;
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(A[mid] >= target) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans == -1 ? n : ans;
}
