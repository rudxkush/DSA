/*
  Author : rudxkush
*/
int Solution::solve(int n, vector<int> &A) {
    vector<int> prefix(n, 0);
    prefix[0] = A[0];
    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + A[i];
    }
    if (prefix[n - 1] % 3) return 0;
    int target = prefix[n - 1] / 3;
    int ans = 0;
    for(int i = 0; i < n-2; i++) {
        if(prefix[i] == target) {
            int j = i + 1;
            while(j < n-1) {
                if(prefix[j] - prefix[i] == target) ans++;
                j++;
            }
        }
    }
    return ans;
}


