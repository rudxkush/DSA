/*
  Author : rudxkush
*/
class Solution {
  public:
    // Function to find equilibrium point in the array .i.e., return (sum[i....L] = sum[L + 2......n-2]) ? L + 1 : -1;
    int findEquilibrium(vector<int> &nums) {
        int n = (int) nums.size();
        int leftSum = 0, totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        for (int i = 0; i < n; i++) {
            int rightSum = totalSum - leftSum - nums[i];
            if(leftSum == rightSum) {
                return i;
            } else {
                leftSum += nums[i];
            }
        }
        return -1;
    }
};
