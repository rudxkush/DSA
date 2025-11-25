int Solution::solve(vector<string> &A) {
    vector<double> nums;
    for(auto strNum : A) {
        nums.push_back(stod(strNum));
    }
    
    sort(nums.begin(), nums.end());
    int n = (int) nums.size();
    int start = 0, end = n - 1;
    while(end - start >= 2) {
        int mid = start + (end - start) / 2;
        double currSum = (nums[start] + nums[mid] + nums[end]);
        if(currSum < 1) {
            start++;
        } else if(currSum > 2) {
            end--;
        } else {
            return 1;
        }
    }
    return 0;
}
