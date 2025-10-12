class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), minLength = INT_MAX;
        int sum = 0;
        while (r < n) {
            sum += nums[r];
            while (sum >= target) {
                minLength = min(minLength, r - l + 1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};
