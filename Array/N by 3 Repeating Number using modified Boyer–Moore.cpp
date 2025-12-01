int Solution::repeatedNumber(const vector<int> &nums) {
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
    int hasAppeared1 = 0, hasAppeared2 = 0;
    for (int i = 0; i < n; i++) {
        if (candidate1 == nums[i]) {
            hasAppeared1 += 1;
        } else if (candidate2 == nums[i]) {
            hasAppeared2 += 1;
        }
    }
    if(hasAppeared1 > n/3) {
        return candidate1;
    } else if(hasAppeared2 > n/3) {
        return candidate2;
    } else {
        return -1;
    }
}
