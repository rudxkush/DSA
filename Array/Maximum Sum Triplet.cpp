int Solution::solve(vector<int> &A) {
    int n = (int) A.size();
    if(n < 3) return 0;
    int maxTripletSum = 0;

    // build suffix
    vector<int> suffix(n);
    int maxElement = A[n-1];
    for(int i = n-1; i >= 0; --i) {
        maxElement = max(maxElement, A[i]);
        suffix[i] = maxElement;
    }

    // build prefix -> using set!
    set<int> prefix;
    prefix.insert(A[0]);
    // int counter = 0;
    for(int i = 1; i <= n-2; i++) {
        int right = suffix[i + 1]; // next greatest element
        // valid triplet[2] check
        if(right <= A[i]) {
            prefix.insert(right);
            continue;
        }

        auto it = prefix.lower_bound(A[i]); // greater or equal to A[i]
        if (it == prefix.begin()) {
            prefix.insert(A[i]);
            continue;
        }
        --it;
        int left = *it;

        int currTripletSum = left + A[i] + right;
        // cout << counter << " : " << left << ", " << A[i] << ", " << right << endl;
        // counter++;
        maxTripletSum = max(maxTripletSum, currTripletSum);
        prefix.insert(A[i]);
    }
    return maxTripletSum;
}
