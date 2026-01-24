int Solution::jump(vector<int> &A) {
    int n = A.size();
    if (n <= 1) return 0;
    if (A[0] == 0) return -1;
    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;
    for (int i = 0; i < n - 1; i++) {
        farthest = max(farthest, i + A[i]);
        if (farthest <= i) return -1;
        if (i == currentEnd) {
            jumps++;
            currentEnd = farthest;

            if (currentEnd >= n - 1) break;
        }
    }
    return jumps;
}
