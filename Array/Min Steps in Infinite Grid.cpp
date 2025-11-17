/*
    Author : rudxkush
*/
int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int n = (int) A.size();
    int minSteps = 0;
    for(int i = 1; i < n; i++) {
        minSteps += max(abs(A[i] - A[i - 1]), abs(B[i] - B[i - 1]));
    }
    return minSteps;
}
