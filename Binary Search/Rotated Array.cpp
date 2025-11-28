int bruteSolution::findMin(const vector<int> &A) {
    int n = (int) A.size();
    for(int i = 1; i < n; i++) {
        if(A[i] < A[i - 1]) {
            return A[i];
        }
    }    
    return A[0];
}

int optimalSolution::findMin(const vector<int> &nums) {
    int start = 0;
    int end = nums.size() - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] > nums[end]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }

    return nums[start];  
}
