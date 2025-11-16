vector<int> Solution::maxset(vector<int> &A) {
    int n = (int) A.size();

    long long sum = 0, maxSum = -1;
    int s = 0;

    int bestLeft = 0, bestRight = -1;  // right = -1 means nothing is chosen yet

    for (int e = 0; e < n; e++) {
        if (A[e] >= 0) {
            sum += A[e];
        } else {
            if (sum > maxSum || 
               (sum == maxSum && (e - s) > (bestRight - bestLeft + 1))) {
                bestLeft = s;
                bestRight = e - 1;
                maxSum = sum;
            }

            // reset
            sum = 0;
            s = e + 1;
        }
    }

    // evaluate last segment [s .. n-1]
    if (sum > maxSum || 
       (sum == maxSum && (n - s) > (bestRight - bestLeft + 1))) {
        bestLeft = s;
        bestRight = n - 1;
        maxSum = sum;
    }

    // no valid segment
    if (bestRight < bestLeft) return vector<int>();

    // build result
    vector<int> ans;
    for (int i = bestLeft; i <= bestRight; i++) {
        ans.push_back(A[i]);
    }

    return ans;
}
