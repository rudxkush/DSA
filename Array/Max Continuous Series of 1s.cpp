vector<int> Solution::maxone(vector<int> &A, int B) {
    int n = (int) A.size();
    int i = 0, j = 0, zeroes = 0, maxLen = INT_MIN;
    int bestLeft = 0;
    while(j < n) {
        if(A[j] == 0) {
            zeroes += 1;
        }
        while(zeroes > B) {
            if(A[i] == 0) {
                zeroes -= 1;
            }
            i += 1;
        }
        if(maxLen < (j - i + 1)) {
            maxLen =  j - i + 1;
            bestLeft = i;
        }
        j++;
    }
    vector<int> ans;
    for(int i = bestLeft; i < maxLen + bestLeft; i++) {
        ans.push_back(i);
    }
    return ans;
}
