/*
    Author: rudxkush
*/
class Solution {
public:
    vector<vector<int>> allSubsets;
    void rec(vector<int>& nums, int i, vector<int>& temp) {
        if (i == nums.size()) {
            allSubsets.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        rec(nums, i + 1, temp);
        temp.pop_back();

        rec(nums, i + 1, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        rec(nums, 0, temp);
        return allSubsets;
    }
};
