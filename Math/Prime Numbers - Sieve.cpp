#include <bits/stdc++.h>
const int bit_size = 1000000;
bitset<bit_size> isPrime;

void buildSieve() {
    for (int i = 2; i * 1LL * i < bit_size; i++) {
        if (isPrime[i]) {
            for (int j = i + i; j < bit_size; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}

vector<int> Solution::sieve(int A) {
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;

    buildSieve();

    vector<int> ans;
    for (int i = 1; i <= A; i++) {
        if (isPrime[i]) ans.push_back(i);
    }
    return ans;
}
