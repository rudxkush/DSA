class Solution {
public:
    long long mod = 1e9 + 7;
    long long power(long long base, long long x) {
        long long res = 1;
        while (x > 0) {
            if (x%2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            x /= 2;
        }
        return res;
    }
    int modInverse(long long a, long long m) {
        return power(a, mod - 2);
    }
    int makeStringSorted(string s) {
        long long rank = 0;
        int n = (int)s.length();
        // pre compute frequeny of all chars in the string s
        vector<int> freq(26, 0);
        for (auto ch : s) {
            freq[ch - 'a']++;
        }
        // pre compute the factorial of all the possible permutations
        vector<long long> fact(n + 1, 1);
        fact[0] = 1;
        for(int i = 1; i <= n; i++) {
            fact[i] =  (fact[i - 1] * i) % mod;
        }
        for(int i = 0; i < n; i++) {
            // how much the permuation count with the unique given   
            // smaller letters will contribute
            int smallerCount = 0;
            for(int j = 0; j < s[i] - 'a'; j++) {
                smallerCount += freq[j];
            }
            // sum all the frequencies of the duplicates
            // denominator: permutation count with duplicates
            long long denominator = 1;
            for(int i = 0; i < 26; i++) {
                denominator = (denominator * fact[freq[i]]) % mod;
            }

            // permution count with the given unique letters
            long long permutationCount = (fact[n - i - 1] * modInverse(denominator, mod)) % mod;

            // how those spaces/permutation count would be utilised by the chars that are smaller to this letter
            // the spaces would also that many which would make up for the entire length
            rank = (rank + smallerCount * permutationCount) % mod;

            freq[s[i] - 'a']--;
        }
        return (int) rank; // zero based value that is rank starts from 0
    }
};
