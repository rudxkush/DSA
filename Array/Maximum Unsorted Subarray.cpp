vector<int> Solution::subUnsort(vector<int> &A) {
    int n = (int) A.size();
    int start = -1, end = -1;

    // find first index that breaks sorted order from left
    for (int i = 0; i < n - 1; i++) {
        if (A[i] > A[i + 1]) {
            start = i;
            break;
        }
    }
    if (start == -1) return { -1 }; // already sorted

    // find first index from right that breaks sorted order
    for (int i = n - 1; i > 0; i--) {
        if (A[i] < A[i - 1]) {
            end = i;
            break;
        }
    }

    int subMin = INT_MAX, subMax = INT_MIN;

    // find min and max inside the unsorted window
    for (int i = start; i <= end; i++) {
        subMin = min(subMin, A[i]);
        subMax = max(subMax, A[i]);
    }

    // extend start to left if needed
    for (int i = 0; i < start; i++) {
        if (A[i] > subMin) {
            start = i;
            break;
        }
    }

    // extend end to right if needed
    for (int i = n - 1; i > end; i--) {
        if (A[i] < subMax) {
            end = i;
            break;
        }
    }

    return { start, end };
}
