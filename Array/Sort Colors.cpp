class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        /*
            Is it a stable sort ? No as the relative ordering of equals gets
           changed!
        */
        for (int i = 0; i < n;) {
            if (nums[i] == 0) {
                swap(nums[i], nums[l]);
                l++;
                i++;
            } else if (nums[i] > 1) {
                if (i > r)
                    break;
                swap(nums[i], nums[r]);
                r--;
            } else {
                i++;
            }
        }
    }
};
/*
    0, 0, 1, 1, 2, 2
          l  h
                i
*/
