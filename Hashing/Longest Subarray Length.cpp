int Solution::solve(vector<int> &nums) {
    int n = (int) nums.size();
    unordered_map<int, int> mp; // { prefix sum till i, i }
    // 0 to -1 transformation
    for(int i = 0; i < n; i++) {
        if(nums[i] == 0) {
            nums[i] = -1;
        }
    }
    int longestOnesLength = 0;
    int running_sum = 0;
    for(int i = 0; i < n; i++) {
        running_sum += nums[i];
        if(running_sum == 1) {
            // As, #1s > #0s by 1
            // we will consider its start from i = 0
            if(longestOnesLength < (i + 1)) {
                longestOnesLength = i + 1;
            }
        } else {
            // As the running sum <= 0 (#1s < #0s), 
            // can we get a better option, if we remove the negative contributing sum index
            if(mp.find(running_sum - 1) != mp.end()) {
                longestOnesLength = max(longestOnesLength, i - mp[running_sum - 1]);
            }
        }
        if(mp.find(running_sum) == mp.end()) mp[running_sum] = i;
    }
    return longestOnesLength;
}
