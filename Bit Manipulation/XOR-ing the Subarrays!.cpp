int Solution::solve(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        long long count = (long long)(i + 1) * (n - i);
        if (count % 2 != 0) {
            ans ^= nums[i];
        }
    }
    
    return ans;
}
