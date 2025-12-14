int Solution::diffPossible(vector<int> &nums, int K) {
    int n = (int) nums.size();
    int i = 0, j = 1;
    while(j < n) {
        int diffK = nums[j] - nums[i];
        if(diffK == K) {
            return 1;
        } else if(diffK > K) {
            i++;
        } else {
            j++;
        } 
        if(i == j) j += 1;
    }
    return 0;
}
