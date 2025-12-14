int Solution::threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int closest;
    int minDiff = INT_MAX;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        int j = i + 1;
        int k = n - 1;
        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            int diff = abs(target - sum);
            if(diff < minDiff) {
                closest = sum;
                minDiff = diff;
            }
            if(sum == target) {
                return sum;
            } else if(sum > target) {
                k--;
            } else {
                j++;
            }
        }
    }
    return closest;
}
