/*
  Author : rudxkush
*/
int Solution::solve(vector<int> &A, int B) {
    int n = (int) A.size();
    vector<int> prefix(n, 0);
    prefix[0] = A[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + A[i];
    }
    
    int maxSum = INT_MIN;
    for(int i = 0; i < B; i++) {
        int currSum = prefix[i - 1] + prefix[n - 1] - prefix[n - 1 - (B - i)];
        maxSum = max(currSum, maxSum);
    }
    return maxSum;
}
