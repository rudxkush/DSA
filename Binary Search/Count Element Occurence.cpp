int binarySearch(const vector<int>& nums, int target, bool flag) {
    int n = (int) nums.size();
    int start = 0, end = n - 1;
    int ans = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            ans = mid;
            if (flag) end = mid - 1;
            else start = mid + 1;
        } else if (nums[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

int findCountUsingInBuiltFunction(const vector<int> &A, int B) {
    int start = lower_bound(A.begin(), A.end(), B) - A.begin();
    int end = upper_bound(A.begin(), A.end(), B) - A.begin();
    return end - start;
}

int findCount(const vector<int> &nums, int target) {
    int left = binarySearch(nums, target, true);
    if (left == -1) return 0;
    int right = binarySearch(nums, target, false);
    return (right - left + 1);
}
