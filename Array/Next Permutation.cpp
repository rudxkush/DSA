vector<int> Solution::nextPermutation(vector<int> &nums) {
    int n = (int) nums.size();
  
    // find the pivot from RHS
    int pivot = -1;
    for(int i = n - 2; i >= 0; i--) {
        if(nums[i] < nums[i + 1]) {
            pivot = i;
            break;
        }
    }
  
    // if it is already the greatest permuation of the given array
    if(pivot == -1) {
        reverse(nums.begin(), nums.end());
        return nums;
    }
  
    // swap nums[pivot] with the right most element that is > nums[pivot]
    int rme = -1;
    for(int i = n - 1; i >= 0; i--) {
        if(nums[i] > nums[pivot]) {
            rme = i;
            break;
        }
    }
    swap(nums[pivot], nums[rme]);
  
    // reverse the array from the pivot + 1 to n-1
    reverse(nums.begin() + pivot + 1, nums.end());
    return nums;
}
