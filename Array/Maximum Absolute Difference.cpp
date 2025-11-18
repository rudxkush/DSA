int Solution::maxArr(vector<int> &A) {
    int N = (int) A.size();
    
    int minPlus = INT_MAX, maxPlus = INT_MIN;
    int minMinus = INT_MAX, maxMinus = INT_MIN;
    
    for(int i = 1; i <= N; i++) {
        int plus = A[i - 1] + i;
        int minus = A[i - 1] - i;
        
        minPlus = min(minPlus, plus);
        maxPlus = max(maxPlus, plus);
        
        minMinus = min(minMinus, minus);
        maxMinus = max(maxMinus, minus);
    }
    
    return max(maxPlus - minPlus, maxMinus - minMinus);
}
