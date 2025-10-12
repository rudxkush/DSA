class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> avgs(n, -1);
        int windowSize = 2 * k + 1;
        if (n < windowSize)
            return avgs;

        long long sum = 0;
        for (int i = 0; i < windowSize; i++) {
            sum += nums[i];
        }
        avgs[k] = sum / windowSize;
        for (int i = k + 1; i + k < n; i++) {
            sum += nums[i + k] - nums[i - k - 1];
            avgs[i] = sum / windowSize;
        }
        return avgs;
    }
};
