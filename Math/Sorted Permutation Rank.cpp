const int mod = 1000003;

int Solution::findRank(string word) {
    int n = (int) word.size();
    int rank = 0;
    // pre-compute the factorial of all the possible permutations
    vector<long long> fact(n + 1, 1);
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] =  (fact[i - 1] * i) % mod;
    }
    
    for (int i = 0; i < n; i++) {
        int remainingLetters = n - i - 1;
        int countSmallerElements = 0;

        for (int j = i + 1; j < n; j++) {
            if (word[j] < word[i]) {
                countSmallerElements++;
            }
        }

        int contribution = (countSmallerElements * fact[remainingLetters]) % mod;
        rank = (rank + contribution) % mod;
    }
    return (rank + 1) % mod;
}
