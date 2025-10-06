class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // a + b = target. So, if we can save index of it
        // and each time check if target - numsEle 
        // and if we see it in cache then we can return the index of this 
        // and if not cache numsEle 
        // key : numsEle, value : index
        unordered_map<int, int> numbersSeen;
        for(int i = 0; i < nums.size(); i++) {
            if(numbersSeen.count(target - nums[i])) {
                return {numbersSeen[target - nums[i]], i};
            }
            numbersSeen[nums[i]] = i;
        }
        return {-1, -1};
    }
};
