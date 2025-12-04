vector<int> Solution::powerfulDivisors(vector<int> &nums) {
    int sieve_limit = INT_MIN;
    for (int num : nums) sieve_limit = max(sieve_limit, num);
    vector<int> fact(sieve_limit + 1, 0);
    for (int i = 1; i <= sieve_limit; i++) {
        for (int j = i; j <= sieve_limit; j+=i) {
            fact[j]++;
        }
    }
    vector<int> prefix_powerful_count(sieve_limit + 1, 0);
    vector<int> results;
    for (int j = 1; j <= sieve_limit; j++) {
        prefix_powerful_count[j] = prefix_powerful_count[j - 1];
        if ((fact[j] & (fact[j] - 1)) == 0) {
            // power of two
            prefix_powerful_count[j]++;
        }
    }
    for (int num : nums) {
        results.push_back(prefix_powerful_count[num]);
    }
    return results;
}
