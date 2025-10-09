class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // will write all three solution as to revise everything to its crux :)
        // O(n^3)
        /*int n = arr.size();
        int maxSum = INT_MIN;
        for(int start = 0; start < n; start++) {
            for(int end = start; end < n; end++) {
                int sum = 0;
                for(int i = start; i <= end; i++) {
                    sum += arr[i];
                }
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;*/
        // O(n^2)
        /*int n = arr.size();
        int maxSum = INT_MIN;
        for(int start = 0; start < n; start++) {
            int sum = 0;
            for(int end = start; end < n; end++) {
                sum += arr[end];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;*/
        // O(n)
        int n = arr.size();
        int maxSum = INT_MIN;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            // At each step, choose to start a new subarray or carry on previous
            sum = max(arr[i], sum + arr[i]);
            // Update global maximum subarray sum found so far
            maxSum = max(maxSum, sum);
        }
        return maxSum;
        
    }
};
