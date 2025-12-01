int Solution::firstMissingPositive(vector<int> &A) {
    sort(A.begin(), A.end());
    while (A[0] <= 0 && (A.begin() != A.end())) {
        A.erase(A.begin());
    }
    if (!A.empty()) {
        vector<int>::iterator it = unique(A.begin(), A.end());
        A.resize(distance(A.begin(), it));
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != i + 1) return i + 1;
        }
    } else {
        return 1;
    }
}

