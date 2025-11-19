const int mod = 1e7;
int Solution::solve(int A, int B) {
    long long sum =  1LL*A + 1LL*B;
    while(sum >= mod) {
        sum = sum - (1LL*mod);
    }
    return (int) sum;
}
