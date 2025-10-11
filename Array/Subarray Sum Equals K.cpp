class Solution {
public:
/*
    Sum[0....i] -> runningSum[i]
    Sum[0....j] -> runningSum[j]
    Sum[j....i] -> runningSum[i] - runningSum[j]
    reqquired of us:   Sum[j....i] == k

    Substitute and we get: runningSum[i] - runningSum[j] = k
    =>  runningSum[j] = runningSum[i] - k;
    if runningSum[j] has ever been cache then add its freqVal to our count. 
*/
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cache;
        cache[0] = 1;
        int subArrCount = 0;
        int runningSum = 0;

        for (int i = 0; i < n; i++) {
            runningSum += nums[i];
            int prevSum = runningSum - k;
            if (cache.count(prevSum)) {
                subArrCount += cache[prevSum];
            }
            cache[runningSum]++;
        }
        return subArrCount;
    }
};
