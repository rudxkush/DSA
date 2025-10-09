class Solution {
  public:
    int smallestSumSubarray(vector<int>& arr) {
        /*
           int n = arr.size();
            int minSum = INT_MAX;
            for(int start = 0; start < n; start++) {
                int sum = 0;
                for(int end = start; end < n; end++) {
                    sum += arr[end];
                    minSum = min(minSum, sum);
                }
            }
            return minSum;
        */
        int n = arr.size();
        int minSum = INT_MAX;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum = min(arr[i], sum+arr[i]);
            minSum = min(sum, minSum);
        }
        return minSum;
    }
};
