class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // At max there can only be 2 element that had appeared > n/3 times
        // Think of it as how can you have 3 element appearing more than n/3
        // times so there are two and that could just be them
        int candidate1 = 0;
        int candidate2 = 0;
        int freq1 = 0;
        int freq2 = 0;

        // moore voting algorithm -> set 1 then set 2
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (candidate1 == nums[i]) {
                freq1++;
            } else if (candidate2 == nums[i]) {
                freq2++;
            } else if (freq1 == 0) {
                freq1 = 1;
                candidate1 = nums[i];
            } else if (freq2 == 0) {
                freq2 = 1;
                candidate2 = nums[i];
            } else {
                freq1--, freq2--;
            }
        }

        // validate both
        int hadAppeared1 = 0, hadAppeared2 = 0;
        for (int i = 0; i < n; i++) {
            if (candidate1 == nums[i]) {
                hadAppeared1 += 1;
            } else if (candidate2 == nums[i]) {
                hadAppeared2 += 1;
            }
        }
        vector<int> ans;
        if (hadAppeared1 > n / 3)
            ans.push_back(candidate1);
        if (hadAppeared2 > n / 3)
            ans.push_back(candidate2);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
