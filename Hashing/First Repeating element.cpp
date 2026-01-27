int Solution::solve(vector<int> &nums) {
    int n = (int) nums.size();
    int left = n;
    unordered_map<int, int> mp;
    int firstRepNumber = -1;
    for(int i = 0; i < n; i++) {
        if(mp.find(nums[i]) != mp.end()) {
            if(left > mp[nums[i]]) {
                firstRepNumber = nums[i];
                left = mp[nums[i]];
            }
        } else {
            mp[nums[i]] = i;
        }
    }
    return firstRepNumber;
}
