class Solution {
public:
    void getAllcombinations(vector<int>& nums, vector<int>& ans, int target, int sum, vector<vector<int>>& subsets, int i) {
        // base case
        if(sum == target) {
            subsets.push_back(ans);
            return;
        }
        if(sum > target) return; 
        for(int j = i; j < nums.size(); j++) { 
            ans.push_back(nums[j]); 
            getAllcombinations(nums, ans, target, sum + nums[j], subsets, j); 
            ans.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> subsets;  
        vector<int> ans; 
        getAllcombinations(nums, ans, target, 0, subsets, 0);  
        return subsets;
    }
};
