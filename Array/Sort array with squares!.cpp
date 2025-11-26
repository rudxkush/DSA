vector<int> Solution::solve(vector<int> &nums) {
    vector<int> result(nums.size()); 
    int l = 0, r = nums.size() - 1;
    int index = nums.size() - 1;
    while(l <= r) {
        if(abs(nums[l]) > abs(nums[r])) {
            result[index] = nums[l] * nums[l];
            l++;
        } else {
            result[index] = nums[r] * nums[r];
            r--;
        }
        index--;
    }
    return result;
}
