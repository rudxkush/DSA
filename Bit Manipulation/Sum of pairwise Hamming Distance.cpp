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
