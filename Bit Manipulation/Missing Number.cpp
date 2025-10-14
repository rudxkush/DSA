class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // indexing since the numbers are from 0 to n
        int n = nums.size();
        vector<int> hash(n + 1, 0);
        for(int i = 0; i < n; i++) {
            hash[nums[i]] = 1;
        }

        for(int i = 0; i < n; i++) {
            if(hash[i] == 0) {
                return i;
            }
        }
        return n;
    }
};
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = n * (n + 1) / 2;  
        int sum = 0;
        for (int it : nums) {
            sum += it;
        }
        return totalSum - sum;
    }
};
