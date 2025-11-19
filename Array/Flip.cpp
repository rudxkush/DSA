/*
    Author : rudxkush
*/
vector<int> Solution::flip(string A) {
    int n = A.size();
    int currSum = 0;
    int maxSum = 0;

    int left = 0;
    int bestLeft = -1, bestRight = -1;

    for (int right = 0; right < n; right++) {
        int contribution = (A[right] == '0') ? 1 : -1;
        currSum += contribution;
        
        if(currSum < 0) {
            currSum = 0;
            left = right + 1;
        } else {
            if(currSum > maxSum) {
                maxSum = currSum;
                bestLeft = left;
                bestRight = right;
            }   
        }
    }

    if (bestLeft == -1) return {};
    return {bestLeft + 1, bestRight + 1};
}
