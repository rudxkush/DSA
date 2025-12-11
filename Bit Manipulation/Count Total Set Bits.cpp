const int mod = 1e9+7;

int largestPowerOfTwoInRange(int n) {
    int p = 0;
    while ((1 << p) <= n) p++;
    return p - 1;
}

int Solution::solve(int A) {
    if (A == 0) return 0; 
    long long x = largestPowerOfTwoInRange(A);
    long long bits = x * (1 << (x - 1));
    long long msb = A - (1 << x) + 1;
    long long rest = A - (1 << x);
    long long ans = (bits % mod + msb % mod + solve(rest % mod)) % mod;        
    return (int) ans;
}
