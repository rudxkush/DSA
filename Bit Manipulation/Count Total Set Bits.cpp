const int mod = 1e9+7;

int closestPowerOfTwo(int num) {
    int power = 0;
    while ((1 << power) <= num) power++;
    return (power - 1);
}

int Solution::solve(int A) {
    if (A == 0) return 0; 
    long long power = closestPowerOfTwo(A);
    long long bits = (1 << (power - 1)) * power;
    long long msb = A - (1 << power) + 1;
    long long rest = A - (1 << power);
    long long ans = (bits % mod + msb % mod + solve(rest)) % mod;        
    return (int) ans;
}
/*
    A = 11
    0-> 0000
    1-> 0001
    2-> 0010
    3-> 0011
    4-> 0100
    5-> 0101
    6-> 0110
    7-> 0111
    8-> 1000
    9-> 1001
    10->1010
    11->1011

    0th bit Index -> alternate 1s and 0s
    1st bit Index -> alternate 1s and 0s after 2 hops
    2nd bit Index -> alternate 1s and 0s after 4 hops

    12 -> 2^2 * 3
    11 - 8 -> 4 MSB bits
    solve(3)
        
    closestPowerOfTwo = 3
    Till it doesn't repeat -> 2^(closestPowerOfTwo - 1) * (closestPowerOfTwo)
    MSB Count -> n - 2^(closestPowerOfTwo) + 1
    rest -> rec(n - 2^(closestPowerOfTwo)) -> stop when A == 0
*/
