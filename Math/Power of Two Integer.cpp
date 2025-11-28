int Solution::isPower(int n) {
    for(int i = 1; i <= sqrt(n); i++) {
        int p = log(n)/log(i);
        if(pow(i, p) == n) return 1;
    }
    return 0;
}
