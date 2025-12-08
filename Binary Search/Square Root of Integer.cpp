int Solution::sqrt(int A) {
    if (A <= 1) return A;
    int start = 1, end = A/2, ans = 0;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        long long square = 1LL * mid * mid;
        if (square == A) return mid;
        else if (square < A) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}
