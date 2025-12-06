long long getWoodCollected(vector<int> &heights, int cutOff) {
    long long ans = 0;
    for(int height : heights) {
        if(height < cutOff) continue;
        ans = ans + (height - cutOff);
    }
    return ans;
}
// O(n * log(maxHeight)) 
int Solution::solve(vector<int> &heights, int K) {
    int s = 0;
    int e = INT_MIN;
    int ans = -1;
    for(int height : heights) e = max(e, height);
    
    while(s <= e) {
        int cutOff = s + (e - s) / 2;
        if(getWoodCollected(heights, cutOff) >= K) {
            ans = cutOff;
            s = cutOff + 1;
        } else {
            e = cutOff - 1;
        }
    }
    
    return ans;
}
