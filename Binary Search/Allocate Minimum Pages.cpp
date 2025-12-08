class Solution {
public:

    int getStudentCount(vector<int>& nums, int pagesThreshold) {
        int currPages = 0, students = 1;
        for (int i = 0; i < (int) nums.size(); i++) {
            if (currPages + nums[i] > pagesThreshold) {
                currPages = 0;
                students++;
            }
            currPages += nums[i];
        }
        return students;
    }

    int findPages(vector<int> &nums, int K) {
        if (K > (int) nums.size()) {
            return -1; 
        }
        
        int start = nums[0], end = nums[0], ans = 0;
        for (int num : nums) {
            start = max(start, num);
            end += num;
        }

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (getStudentCount(nums, mid) <= K) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }

};
