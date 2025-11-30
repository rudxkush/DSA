int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    vector<bool> mins(n, false);
    int answer = 0, minElement = INT_MAX;   
    for(int i = 0; i < n; i++) {
        if (A[i] < minElement) {
            minElement = A[i];
            mins[i] = true;
        }
    }
    int i = n - 1, j = n - 1;
    while(i >= 0) {
        if (!mins[i]) {
            i--;
            continue;
        } while(A[j] < A[i] && j > i) {
            j--;
        }
        if (j - i > answer) {
            answer = j - i;
        }
        i--;
    } 
    return answer;
}

