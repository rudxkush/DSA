vector<int> Solution::flip(string A) {
    int n = A.size();
    int currSum = 0;
    int maxSum = 0;

    int left = 0;
    int bestLeft = -1, bestRight = -1;

    for (int i = 0; i < n; i++) {
        // convert 0 -> +1, 1 -> -1
        int val = (A[i] == '0') ? 1 : -1;
        currSum += val;

        if (currSum < 0) {
            currSum = 0;
            left = i + 1;    // reset window
        } else {
            if (currSum > maxSum) {
                maxSum = currSum;
                bestLeft = left;
                bestRight = i;
            }
        }
    }

    if (bestLeft == -1) return {};
    return {bestLeft + 1, bestRight + 1};
}
