int Solution::pow(int A, int B, int C) {
    if (C == 1) return 0;
    long long num = A;
    long long power = B;
    long long mod = C;
    num = ((num % mod) + mod) % mod;
    if (power < 0) {
        return -1; 
    }
    long long result = 1;
    long long base = num;
    while (power > 0) {
        if (power % 2) result = (result * base) % mod;
        base = (base * base) % mod;
        power /= 2;
    }
    
    return (int)result;
}
