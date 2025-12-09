int Solution::solve(vector<int> &nums) {
    int n = nums.size();
    int start = 0, end = n - 1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(mid == start && mid == end) return nums[mid];
        else if(mid == start) {
            if(nums[mid] > nums[mid + 1]) return nums[mid];
            else start = mid + 1;
        }
        else if(mid == end) {
            if(nums[mid] > nums[mid - 1]) return nums[mid];
            else end = mid - 1;
        }
        else {
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return nums[mid];
            else if(nums[mid] > nums[mid - 1]) start = mid + 1;
            else end = mid - 1;
        }
    }
    return -1;
}
