int Solution::solve(vector<int> &nums) {
    int n = nums.size();
    int left = 0, right = n - 1, ans = -1;
    while(left <= right) {
        int mid = (left + right) >> 1;
        if((mid == 0 || nums[mid] >= nums[mid - 1]) && (mid == n-1 || nums[mid] >= nums[mid + 1])) {
            ans = nums[mid]; 
            break;
        }
        if((mid == 0 || nums[mid] >= nums[mid-1])) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}
