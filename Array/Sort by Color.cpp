void Solution::sortColors(vector<int> &A) {
    int n = (int) A.size();
    int low = 0, high = n - 1;
    for(int i = 0; i <= high; ) {
        if(A[i] == 0) {
            swap(A[i], A[low]);
            low++; i++;
        } else if(A[i] == 1) {
            i++;
        } else {
            swap(A[i], A[high]);
            high--;
        }
    }
}
