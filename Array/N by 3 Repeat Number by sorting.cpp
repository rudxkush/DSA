int Solution::repeatedNumber(const vector<int> &A) {
    int n = (int) A.size();
    if(n < 3) return A[0];   // trivial case

    vector<int> v = A;
    sort(v.begin(), v.end());

    int k = n / 3;

    for(int i = 0; i < k; i++) {
        if(v[i] == v[i + k]) 
            return v[i];

        if(v[i + k] == v[i + 2*k]) 
            return v[i + k];

        int r = v.size() - 1 - i;
        if(v[r] == v[r - k]) 
            return v[r];
    }

    return -1;
}
