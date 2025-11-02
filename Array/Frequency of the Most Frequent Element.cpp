/*  
    Author : rudxkush
*/
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        // Sort the array as only Increment operations are allowed!
        sort(nums.begin(), nums.end());

        // Constructing Prefix Sum
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
            prefix[i] = nums[i] + prefix[i - 1];

        // We would try to find a Window where,
        // (nums[i]*len - prefix[l....i] <= k) is satisfied
        int maxPossible = 1; // number itself!
        for (int i = 0; i < n; i++) {
            // As the array is sorted... we would do binary search
            // To locate a left that satisfies the above condition
            int right = i;
            int left = 0;
            int bestLen = 0;
            while (left <= right) {
                int mid = (left + right) / 2;
                int len = i - mid + 1;
                long long targetSum = 1LL * nums[i] * len;
                long long currentSum = prefix[i] - ((mid == 0) ? 0 : prefix[mid - 1]);
                long long  operations_required_to_reach_targetSum = targetSum - currentSum;

                if(operations_required_to_reach_targetSum <= k) {
                    bestLen = len;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            maxPossible = max(maxPossible, bestLen);
        }
        return maxPossible;
    }
};
