int Solution::solve(vector<int> &nums, int k) {
    int i = 0, n = (int) nums.size(), zeroes = 0, 
    lsLen = INT_MIN, ones = 0;
    for(int j = 0; j < n; j++) {
        if(nums[j] == 1) {
            ones++;
        } else {
            zeroes++;
        }
        while(zeroes > k) {
            if(nums[i] == 0) {
                zeroes -= 1;
            }
            i++;
        }
        // if(zeroes <= k)
            lsLen = max(lsLen, j - i + 1);
    }
    return lsLen;
}
