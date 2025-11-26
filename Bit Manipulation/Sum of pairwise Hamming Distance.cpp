int bruteSolution::hammingDistance(const vector<int> &A) {
    int n = A.size();
    long long ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int dist = 0;
            for(int bitIdx = 0; bitIdx < 32; bitIdx++) {
                int bitI = (A[i] >> bitIdx) & 1;
                int bitJ = (A[j] >> bitIdx) & 1;
                if (bitI ^ bitJ) dist++;
            }
            ans += dist;
        }
    }

    return ans % 1000000007;
}
/*
    Author : rudxkush
*/
const int MOD = 1e9+7;
int optimalSolution::hammingDistance(const vector<int> &A) {
    int n = A.size();
    long long ans = 0;

    for(int bitIdx = 0; bitIdx < 32; bitIdx++) {
        int count_of_ones = 0, count_of_zeroes = 0;
        for(int i = 0; i < n; i++) {
            bool isOne = (A[i] & (1 << bitIdx));
            if(isOne) count_of_ones++;
            else count_of_zeroes++; 
        }
        ans = (ans + (2LL * count_of_ones * count_of_zeroes) % MOD) % MOD;
    }

    return ans;
}
