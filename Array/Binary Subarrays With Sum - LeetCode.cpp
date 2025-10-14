class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int i = 0, j = 0, n = nums.size(), ans = 0, sum = 0;
        while(j < n) {
            sum += nums[j];
            while(sum > k) {
                sum -= nums[i];
                i++;
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal - 1);
    }
};
