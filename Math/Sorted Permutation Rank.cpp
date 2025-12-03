const int mod = 1000003; 
int factorial(int num) {
    int ans = 1; 
    while (num >= 1) {
        ans = (ans * num) % mod;
        num--;
    }
    return ans % mod;
}

int Solution::findRank(string word) {
    int n = (int) word.size();
    int rank = 0; 

    for (int i = 0; i < n; i++) {
        int remainingLetters = n - i - 1;
        int countSmallerElements = 0;

        for (int j = i + 1; j < n; j++) { 
            if (word[j] < word[i]) {
                countSmallerElements++;
            }
        }
        int contribution = (countSmallerElements * factorial(remainingLetters)) % mod;
        rank = (rank + contribution) % mod;
    }
    return (rank + 1) % mod;
}
