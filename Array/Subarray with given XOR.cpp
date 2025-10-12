int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    unordered_map<int, int> prefix; // xorVal, freq
    prefix[0] = 1;
    int runningXor = 0;
    int count = 0;
    for(int i = 0; i < n; i++) {
        runningXor = runningXor ^ A[i];
        int previousXor = B ^ runningXor;
        if(prefix.count(previousXor)) {
            count += prefix[previousXor];
        }
        prefix[runningXor]++;
    }
    return count;
}
/*
    Intuiton:
    preXor[i] = A[0] ^ A[1] ^ A[2] ...... A[i]
    preXor[j] = A[0] ^ A[1] ^ A[2] ...... A[j]
    
    preXor[j...i] = targerVal, In this case it is B   
    preXor[j...i] = preXor[i] ^ preXor[j], becasue then the numbers from 0 to j would be removed.

    preXor[i] ^ preXor[j] = B
    Try to look in the cache for preXor[i]/runningXor ^ B and add its frequency to the count
*/
