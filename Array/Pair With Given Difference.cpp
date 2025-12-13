int Solution::solve(vector<int> &arr, int x) {
    sort(arr.begin(), arr.end());
    int i = 0, j = 1;
    if(x < 0) x = x * -1;
    while(j < arr.size()) {
        int diff = arr[j] - arr[i];
        if(diff == x) return 1;
        else if(diff > x) i++;
        else j++;
        if(i == j) j++;
    }
    return 0;
}
