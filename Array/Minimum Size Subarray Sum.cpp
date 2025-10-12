class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, n = nums.size(), minLength = INT_MAX;
        int sum = 0;
        while (l < n) {
            if(sum < target) {
                if (r == n) break;
                sum += nums[r];
                r++;
            } else {
                minLength = min(r - l, minLength);
                sum -= nums[l];
                l++;
            }
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};
