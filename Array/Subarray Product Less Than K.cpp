class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k <= 1) return 0; 

        int l = 0, r = 0, count = 0;
        long long product = 1;

        while(r < n) {
            product *= nums[r]; 
            while(product >= k && l <= r) { 
                product /= nums[l];
                l++;
            }
            count += r - l + 1; 
            r++;
        }

        return count;
    }
};
