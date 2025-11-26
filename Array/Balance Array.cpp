/*
    Author : rudxkush
*/
int Solution::solve(vector<int> &nums) {
    int n = (int) nums.size();
    // Pre-compute prefixOddSum, prefixEvenSum
    // suffixOddSum, suffixEvenSum from both the sides
    vector<int> leftOddSum(n), leftEvenSum(n);
    vector<int> rightOddSum(n), rightEvenSum(n);
    
    // Compute left side swifted by one index
    long long runningOddSum = 0, runningEvenSum = 0;
    for(int i = 0; i < n; i++) {
        leftEvenSum[i] = runningEvenSum;
        leftOddSum[i] = runningOddSum;
        if(i%2 == 0) { // Even index!
            runningEvenSum += nums[i];
        } else {
            runningOddSum  += nums[i];
        }
    }
    
    // Compute right side swifted by one index
    runningEvenSum = 0, runningOddSum = 0;
    for(int i = n - 1; i >= 0; i--) {
        rightEvenSum[i] = runningEvenSum;
        rightOddSum[i] = runningOddSum;
        if(i%2 == 0) { // Even index!
            runningEvenSum += nums[i];
        } else {
            runningOddSum  += nums[i];
        }
    }
    
    int specialElements = 0;
    for(int i = 0; i < n; i++) {
        // As the even and odd indices interchange!
        if(leftEvenSum[i] + rightOddSum[i] == leftOddSum[i] + rightEvenSum[i]) {
            specialElements++;
        }
    }
    return specialElements;
}
/*
        nums = [2, 1, 6, 4] 
        leftOdd = { 0 0 1 1 }
        leftEven = { 0 2 2 8 }
        rightEven = { 6 6 0 0 }
        rightOdd = { 5 4 4 0 }

        0, 6 !=  0, 5
        0, 6 !=  2, 4
        0, 6 ==  2, 4
        1, 0 !=  2, 4
        1, 0 !=  8, 0
        2 + 5 = 1 + 8
        8 + 6 = 5 + 4

*/
