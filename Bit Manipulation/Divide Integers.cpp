int Solution::divide(int num, int x) {
    long long dividend = num, divisor = x;
    long long ans = 0;
    int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
    dividend = abs(dividend);
    divisor = abs(divisor);
    long long counter = 0;
    for (int i = 31; i>= 0; i--) {
        if (counter + (divisor << i) <= dividend) {
            counter += (divisor << i);
            ans |= 1LL << i;
        }
    }
    ans *= sign;
    return ans >= INT_MAX || ans < INT_MIN ? INT_MAX : ans;
}
