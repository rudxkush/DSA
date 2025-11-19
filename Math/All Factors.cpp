vector<int> Solution::allFactors(int A) {
    vector<int> factors;
    for(int i = 1; i <= sqrt(A); i++) {
        if((A % i) == 0) {
            factors.push_back(i);
            if(A/i != i) factors.push_back(A/i);
        }
    }
    sort(factors.begin(), factors.end());
    return factors;
}
