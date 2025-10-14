class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        int count = 0;
        int l = 0, n = nums.size();
        int ans = 0;
        for (int r = 0; r < n; r++) {
            if (nums[r] % 2 != 0) {
                count++;
            }
            while (count > k) {
                if (nums[l] % 2 != 0) {
                    count--;
                }
                l++;
            }
            if (count <= k) {
                ans += r - l + 1;
            }
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};
