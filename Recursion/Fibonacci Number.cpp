class Solution {
public:
    vector<int> dp;
    int rec(int n) {
        if (n < 2)
            return n;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = rec(n - 1) + rec(n - 2);
    }
    int fib(int n) {
        dp.clear();
        dp.resize(n + 1, -1);
        return rec(n);
    }
};
