int Solution::solve(vector<int> &nums, int target) {
    int s = 0, e = (int) nums.size() - 1;
    int n = nums.size();

    while(s <= e) {
        int mid = s + (e - s) / 2;
        if(nums[mid] == target) return mid;
        int left  = (mid > 0) ? nums[mid - 1] : INT_MIN;
        int right = (mid < n - 1) ? nums[mid + 1] : INT_MIN;
        
        // We are at peak
        if(nums[mid] > left && nums[mid] > right) {
            if(target > nums[mid]) return -1;
            if(target >= nums[0]) e = mid - 1;
            else s = mid + 1;
        }

        // We are on the Increasing side
        else if(nums[mid] > left && nums[mid] < right) {
            if(target < nums[mid]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        // We are on the Decreasing side
        else if(nums[mid] < left && nums[mid] > right) {
            if(target < nums[mid]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
    }
    return -1;
}
