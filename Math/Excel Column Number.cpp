int Solution::titleToNumber(string A) {
    int n = (int) A.size();
    int ans = 0;
    int base = 1;
    for(int i = n - 1; i >= 0; i--) {
        ans = ans + base * (A[i] - 'A' + 1);
        base *= 26;
    }
    return ans; 
}
