class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int freq = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(freq == 0) {
                candidate = nums[i];
                freq = 1;
            } else {
                if(nums[i] == candidate) {
                    freq++;
                } else {
                    freq--;
                }
            }
        }
        // validate that candidate has appeared > n/2 times
        int hadAppeared = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == candidate) {
                hadAppeared += 1;
            }
        } 
        return hadAppeared > n/2 ? candidate : -1;
    }
};
