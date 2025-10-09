class Solution {
  public:
  int maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        int maxSum = INT_MIN;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum = max(arr[i], sum + arr[i]);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
        
    }
    int minSubarraySum(vector<int>& arr) {
        int n = arr.size();
        int minSum = INT_MAX;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum = min(arr[i], sum+arr[i]);
            minSum = min(sum, minSum);
        }
        return minSum;
    }
    int maxCircularSum(vector<int> &arr) {
        int n = arr.size();
        
        int totalSum = 0;
        for(int a : arr) totalSum += a;
        
        int minSum = minSubarraySum(arr);
        int maxSum = maxSubarraySum(arr);
        
        // calculate max circular sum
        int cirSum = totalSum - minSum;
        
        if(maxSum > 0) {
            return max(maxSum, cirSum);
        }
        return maxSum; // As cirSum would be more negative than this!!
    }
};
