vector<int> Solution::searchRange(const vector<int> &A, int target) {
    int start = -1, end = -1;
    int n = (int) A.size();
    int i = 0, j = n - 1;
    while(i <= j) {
        int mid = i + (j - i) / 2;
        if(A[mid] == target) {
            start = mid;
            j = mid - 1;
        } else if(A[mid] < target) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }
    i = 0, j = n - 1;
    while(i <= j) {
        int mid = i + (j - i) / 2;
        if(A[mid] == target) {
            end = mid;
            i = mid + 1;
        } else if(A[mid] < target) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    } 
    return {start, end};
}
