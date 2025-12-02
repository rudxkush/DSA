int Solution::reverse(int A) {
    long long ans = 0;
    while(A != 0) {
        ans *= 10;
        ans += A%10;
        A /= 10;
    }
    if (ans > INT_MAX || ans < INT_MIN) return 0;
    else return ans;
}
