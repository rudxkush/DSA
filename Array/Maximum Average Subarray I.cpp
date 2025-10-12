class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAverage = -1e9;
        int n = nums.size();
        if(k > n) return -1e9;
        double avg = 0, sum = 0;
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }
        avg = sum / k;
        maxAverage = max(maxAverage, avg);
        for(int i = 1; i + k <= n; i++) {
            sum = sum + nums[i + k - 1] - nums[i - 1];
            avg = sum/k;
            maxAverage = max(maxAverage, avg);  
        }
        return maxAverage;
    }
};
/*
    (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
    -5 - 6 + 50 + 3 / 4 = 42 / 4 = 10.5

    newWindow = avg * 4 = 51 => 51 - 12 + 3 = 42       
*/
